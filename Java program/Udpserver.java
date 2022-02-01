import java.net.DatagramPacket;
import java.net.DatagramSocket;

import java.net.InetAddress;
import java.util.Scanner;

public class Udpserver {
    public static void main(String[] args) throws Exception {
        DatagramSocket ds = new DatagramSocket();
        String str = "";
        Scanner sc = new Scanner(System.in);
        System.out.println("\n Enter the message : ");
        str = sc.nextLine();
        InetAddress ip = InetAddress.getByName("127.0.0.1");
        DatagramPacket dp = new DatagramPacket(str.getBytes(), str.length(), ip, 3000);
        ds.send(dp);
        ds.close();

    }
}
