package server;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Date;

/**
 * @author      Berk Ecer 
 * @version     1.8                 
 * @since       2016-05-01         
 */
public class ServerMain {
	public static ArrayList<String> outputLines = new ArrayList<String>(); /* This array list stores the lines of output. */
	public static void main(String args[]) throws IOException {
		String os; /*Each variable named with os(os1,os2,os3....) used for printing out the messages. They means output string.*/
		/*When server starts message will be append to log file */
		System.out.println(GetCurrentDate()+"SERVER - STARTED" +" - Started on port " + args[0]);
		os = GetCurrentDate()+"SERVER - STARTED" +" - Started on port " + args[0];
		appendContents("log.txt", os);
		
		/* Socket Definitions for Client - Server Communication */
		ServerSocket s1 = new ServerSocket(Integer.parseInt(args[0]));
		Socket ss = s1.accept();
		
		/* When client connected, print out the connection established message. */
		System.out.println(GetCurrentDate()+"SERVER - CONNECTION" +" - Client connected on port " + args[0]);
		String os9 = GetCurrentDate()+"SERVER - CONNECTION" +" - Client connected on port " + args[0];
		appendContents("log.txt", os9);
		
		/* Scanner to read parameters passed by client to server */
		Scanner sc = new Scanner(ss.getInputStream());
		
		/* Read the strings wrote by client to socket */
		ArrayList<String> params = new ArrayList<String>();
		for (int i = 0; i < 3; i++) {
			params.add(sc.next());
		}
		
		/* Print out clients request. */
		System.out.println(GetCurrentDate()+"SERVER - GET" +" - Client made a request. Find \"" + params.get(1) + "\" subsequence on \"" + params.get(0) + "\" with " + params.get(2) + " threads.");
		String os8 = GetCurrentDate()+"SERVER - GET" +" - Client made a request. Find \"" + params.get(1) + "\" subsequence on \"" + params.get(0) + "\" with " + params.get(2) + " threads.";
		appendContents("log.txt", os8);
		
		/*Than connection between client - server closed. Print out. */
		s1.close();
		sc.close();
		System.out.println(GetCurrentDate()+"SERVER - STOPPED" +" - Stopped on port " + args[0]);
		String os7 = GetCurrentDate()+"SERVER - STOPPED" +" - Stopped on port " + args[0];
		appendContents("log.txt", os7);
		
		/* Open and read input.txt file, params.get(0) = "input.txt"*/
		BufferedReader reader = new BufferedReader(new FileReader(params.get(0)));
		ArrayList<String> lines = new ArrayList<String>(); /* Stores the lines of input. */
		String line;
		while ((line = reader.readLine()) != null) {
			lines.add(line);
		}
		reader.close(); /* Close reader */
		
		/* Join all the lines because there are \n character at each lines and that destroy index mechanism.*/
		String all_data = "";
		for (String s : lines) {
			all_data += s;
		}
		
		/* Get thread count from params. */
		int Thread_Count = Integer.parseInt(params.get(2));
		ArrayList<Thread> Thread_List = new ArrayList<Thread>();
		ArrayList<String> Pieces = new ArrayList<String>();
		int beginIndex = 0; /* Store each threads text starting index based on input. */
		int thread_payload = all_data.length() / Thread_Count; /*Each threads payload*/
		/*Create normal threads*/
		for (int i = 1; i <= Thread_Count; i++) {
			String t_name = "Thread " + i;
			Thread  t;
			if(i==Thread_Count){
				String piece = all_data.substring(beginIndex);
				Pieces.add(piece);
				int sender = Integer.parseInt(args[0])+1;
				t = new Thread(new Worker(sender,t_name,i,piece,params.get(1),beginIndex));
			}else{
				String piece = all_data.substring(beginIndex, beginIndex + thread_payload);
				Pieces.add(piece);
				int sender = Integer.parseInt(args[0])+1;
				t = new Thread(new Worker(sender,t_name,i,piece,params.get(1),beginIndex));
			}
			beginIndex += thread_payload;
			Thread_List.add(t);
			System.out.println(GetCurrentDate()+"SERVER - CREATE" +" - Thread "+ i +" is created.");
			String os6 = GetCurrentDate()+"SERVER - CREATE" +" - Thread "+ i +" is created.";
			appendContents("log.txt", os6);
		}
		/*This part generates a text for extra thread. Gets parts from pay loads. 
		 * piece from end of first, piece from start of second pay load. 
		 * And combines them into a one string variable*/
		int count = params.get(1).length() - 1;
		ArrayList<String> strings = new ArrayList<String>();
		ArrayList<Integer> integers  = new ArrayList<Integer>();
		for (int i = 0; i < Pieces.size(); i++) {
			String string_send;
			int start_index;
			if(i==0){
				start_index =Pieces.get(i).length() - count;
			}if(i!=Pieces.size()-1){
				start_index =(thread_payload*i) + Pieces.get(i).length() - count;
				String last = Pieces.get(i).substring(Pieces.get(i).length() - count);
				String first = Pieces.get(i+1).substring(0, Math.min(Pieces.get(i+1).length(), count));
				string_send = last + first; 
				strings.add(string_send);
				integers.add(start_index);
			}
		}
		/* Create one extra threads for working in between pay loads. */
		String lastname = "Thread " + (Thread_Count+1);
		Thread lastthread = new Thread(new Worker(lastname,Thread_Count+1,strings,integers,params.get(1)));
		Thread_List.add(lastthread);
		
		/* Print out message. */
		System.out.println(GetCurrentDate()+"SERVER - CREATE" +" - Thread "+ (Thread_Count+1) +"(extra) is created.");
		String os5 = GetCurrentDate()+"SERVER - CREATE" +" - Thread "+ (Thread_Count+1) +"(extra) is created.";
		appendContents("log.txt", os5);
		
		/* Start all the threads. */
		for (Thread t : Thread_List) {
			t.start();
		}
		for (Thread t : Thread_List) {
			try {
				t.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		
		
	}
	/**
	 * GetCurrentDate
	 * This method get date time information from system.
	 * @return current time
	 */
	public static String GetCurrentDate(){
		Date date= new Date();
		return "["+new Timestamp(date.getTime())+"] - ";
	}
	/**
	 * Append Contents
	 * This methods prints out the given content to a file.
	 * @param sFileName file name for output
	 * @param sContent content to write
	 */
	public static synchronized void appendContents(String sFileName, String sContent) {
        
		try {

            File oFile = new File(sFileName);
            if (!oFile.exists()) {
                oFile.createNewFile();
            }
            if (oFile.canWrite()) {
                BufferedWriter oWriter = new BufferedWriter(new FileWriter(sFileName, true));
                oWriter.write(sContent + "\n");
                oWriter.close();
            }

        }
        catch (IOException oException) {
            throw new IllegalArgumentException("Error appending/File cannot be written: \n" + sFileName);
        }
    }
}
