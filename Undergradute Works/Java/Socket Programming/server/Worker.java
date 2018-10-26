package server;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;

/**
 * @author      Berk Ecer 
 * @version     1.8                 
 * @since       2016-05-01         
 */
public class Worker implements Runnable {
	public static Socket SOS;
	public static PrintStream PS;
	public static int PS_CON = 0;
	public static int CON = 0;
	public static int finder = 1;
	String name;
	int thread_id;
	String text;
	ArrayList<String> text_list = new ArrayList<String>();
	ArrayList<Integer> index_list = new ArrayList<Integer>();
	String key;
	int baseIndex;
	int type;
	
	/* This is the constructor of our threads. As we can see there is a socket connection and print stream 
	 * in here for sending information to client. There is a singleton like pattern here that provides to 
	 * create just one instance of socket */
	public Worker(int portNumber,String tname, int tid, String ttext,String tkey,int bi) throws UnknownHostException, IOException{
		if(CON == 0){
			SOS = new Socket("127.0.0.1", portNumber);
			PS = new PrintStream(SOS.getOutputStream());
			CON = 1;
		}
		name = tname;
		thread_id = tid;
		text = ttext;
		key = tkey;
		baseIndex = bi;
		type = 1 ;
	}
	/* This is the constructor of extra thread. That doesn't need any socket or printStream creation
	 * first thread who is created generate these instances this one never do. But this one use text list 
	 * and index list. In text list there are text pieces combined from 1 piece from end + 1 piece from start
	 * of each pay load. In index list there are base indexes of these pieces.*/
	public Worker(String tname, int tid, ArrayList<String> ttextlist,ArrayList<Integer> tindexlist,String tkey){
		name = tname;
		thread_id = tid;
		key = tkey;
		text_list = ttextlist;
		index_list = tindexlist;
		type = 2 ;
	}
	/**
	 *  This method is the threads run function. That means this method will be executed at the same
	 *  time from different threads. It is a over ride function from super class runnable.
	 */
	@Override
	public void run() {
		try {
			if(type == 1){ /* Normal Threads */
				for (int i = 0; i < text.length(); i++) { /* Brute force search in here.*/
					if(i+key.length()<=text.length()){
						int checker = 0;
						int printer = i + baseIndex;
						for (int j = 0; j < key.length(); j++) {
							if(text.charAt(i+j)==key.charAt(j)){
								checker++;
							}
						}
						if(checker == key.length()){ /*If it finds a combination it sends it to client.*/
							/* Print the log. os1 = output string */
							System.out.println(ServerMain.GetCurrentDate() + name + " - FIND - \""+key+"\" subsequence is found at index " +printer +".");
							String os1 =ServerMain.GetCurrentDate() + name + " - FIND - \""+key+"\" subsequence is found at index " +printer +".";
							ServerMain.appendContents("log.txt", os1);
							
							while(PS_CON == 0){ /* This is a lock system that I created. PS_CON is Print Stream controller */
								/* If ps_con = 0 that means no one is trying to write to client, its available.*/
								PS_CON = 1; /* Lock print stream. */
								PS.println(key + ":" + printer+":"+name+":"+finder+"%"); /* Send message to client. That % used for separating lines.*/
								finder++; /* finder is the order of text has been found. */
							}
							PS_CON = 0; /* Release lock. */
							
						}
					}
				}
			}else{ /* Extra Thread */
				/* This thread do the search operations explained for each text in text_list. And other things are same. */
				for (int x = 0; x < text_list.size(); x++) {
					String text = text_list.get(x);
					for (int i = 0; i < text.length(); i++) {
						if(i+key.length()<=text.length()){
							int checker = 0;
							int printer = i + index_list.get(x);
							for (int j = 0; j < key.length(); j++) {
								if(text.charAt(i+j)==key.charAt(j)){
									checker++;
								}
							}
							if(checker == key.length()){
								System.out.println(ServerMain.GetCurrentDate() + name + " - FIND - \""+key+"\" subsequence is found at index " +printer +".");
								String os3 = ServerMain.GetCurrentDate() + name + " - FIND - \""+key+"\" subsequence is found at index " +printer +".";
								ServerMain.appendContents("log.txt", os3);
								
								while(PS_CON == 0){ /*Locking and releasing */
									PS_CON = 1;
									PS.println(key + ":" + printer+":"+name+":"+finder+"%");/* that % used for separating lines.*/
									finder++;
								}
								PS_CON = 0;
								
							}
						}
					}
				}
			}
			Thread.sleep(500);
			System.out.println(name+ " is done.");
			String os9 = ServerMain.GetCurrentDate() + name + " - END - Thread has been stopped.";
			ServerMain.appendContents("log.txt", os9);
			
			
		} catch (Exception e) {}
	}
	

}
