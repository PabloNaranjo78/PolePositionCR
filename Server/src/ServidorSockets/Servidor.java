package ServidorSockets;

import GsonManager.Informacion;
import com.google.gson.Gson;
import com.google.gson.stream.JsonToken;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.stream.Stream;


public class Servidor {
    public static void main(String[] args) {
        ServerSocket servidor = null;
        Socket sc = null; //Socket del cliente
        //BufferedReader in;
        DataInputStream in;
        PrintStream out;

        final int puerto = 5000;

        Gson gson = new Gson();

        try {
            servidor = new ServerSocket(puerto);
            System.out.println("Servidor iniciado");

            while (true){
                sc = servidor.accept();
                System.out.println("Cliente conectado");

                //in = new BufferedReader(new InputStreamReader(sc.getInputStream()));
                in = new DataInputStream(sc.getInputStream());

                out = new PrintStream(sc.getOutputStream());

//Hay que poner nombres más bonitos a las variables
                int in1;
                char res = 'a';
                String finalString = "";

                do {
                    in1 = in.read();
                    res = (char)in1;
                    System.out.println(res);
                    finalString+= res;
                }
                while (res!='}');

                System.out.println(finalString);
              //  System.out.println(in.read());
//                String json = in.readLine();//Se recibe el json
//                System.out.println(json);



                //Informacion mensaje = gson.fromJson(json,Informacion.class);//Se deserializa el json

                //System.out.println(mensaje.paquete());//Se imprimen los datos del json

                //out.writeUTF(json);//Se envia el json a los clientes
                char letra = 'a';
                out.println("Hola C desde Java");

                sc.close();
                System.out.println("Cliente desconectado");

            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
