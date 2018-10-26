package client;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.Writer;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * @author      Berk Ecer 
 * @version     1.8                 
 * @since       2016-05-01         
 */
public class ClientMain {

	public static void main(String args[]) throws UnknownHostException, IOException, InterruptedException {
		System.out.println("Client started");
		for (String s : args) {
			System.out.println("C: " + s);
		}
		/* Get parameters. */
		String message = args[1] + " " + args[2] + " " + args[3];
		
		/* Connect to server. */
		Socket s = new Socket("127.0.0.1", Integer.parseInt(args[0]));
		System.out.println("Client Connection Established");

		System.out.println("Client Requested: " + message);
		
		/* Write request to sockets print stream. So server will read them. */
		PrintStream p = new PrintStream(s.getOutputStream());
		p.println(message);
		
		/* Close connection.*/
		s.close();
		
		/* Open a socket in order to listen and wait information from threads. */
		ServerSocket CLIENT_SERVER = new ServerSocket(Integer.parseInt(args[0]) + 1);
		Socket SOCKET = CLIENT_SERVER.accept();
		
		/* Start a scanner to scan information that will be printed by threads.*/
		Scanner scanner = new Scanner(SOCKET.getInputStream());
		
		/* Read all the information to results array list.*/
		ArrayList<String> results = new ArrayList<String>();
		String res2 = "";
		while (scanner.hasNext()) {
			String res = scanner.next();
			res2 += res;
		}
		if (!res2.equals("")) {
			res2 += "\n";
			results.add(res2);

		}
		
		/* Separate the lines from each % sign. Add the to output array list. 
		 * there will always just one value in results array list which contains everything, 
		 * so split zero index. */
		ArrayList<String> output = new ArrayList<String>();
		String lines[] = results.get(0).split("%");
		for (String string : lines) {
			if(string.length()>5){
				output.add(string);
			}
		}
		
		/* Than sort the output by looking the starting index of founded combinations. */
		/* And save the sorted results to sorted array list. */
		ArrayList<Integer> vals = new ArrayList<Integer>();
		for (String string : output) {
			String pieces[] = string.split(":");
			vals.add(Integer.parseInt(pieces[1]));
		}
		/* This part will sort the lines. */
		Collections.sort(vals);
		ArrayList<String> sorted = new ArrayList<String>();
		for (Integer integer : vals) {
			CharSequence cs = integer.toString();
			for (String ss : output) {
				if(ss.contains(cs)){
					sorted.add(ss);
					break;
				}
			}
		}
		
		/* Print out the sorted results. To out.txt file. */
		Writer writer = null;

		try {
		    writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("out.txt"), "utf-8"));
		    for (String string : sorted) {
				writer.write(string + "\n");
				System.out.println(string);
			}
		} catch (IOException ex) {
		  /* report */
		} finally {
		   try {writer.close();} catch (Exception ex) {/*ignore*/}
		}
		
		/* Close connection to threads. And close scanner. */
		CLIENT_SERVER.close();
		scanner.close();
		
		System.out.println("Client Ended");
	}

}
