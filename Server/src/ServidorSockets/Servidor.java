package ServidorSockets;

import Eventos.Ventana;
import GsonManager.Informacion;
import com.google.gson.Gson;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Servidor {

    /***
     * Este metodo se encarga de inicar el servidor, la ventana y el manejador de eventos.
     */
    public void iniciarServidor() {
        Ventana ventana = new Ventana();
        ServerSocket servidor = null;
        Socket sc = null; //Socket del cliente
        DataInputStream in;
        PrintStream out;
        DataOutputStream out2;

        final Integer puerto = 5000;

        Informacion jose = new Informacion("jose","Sanchez",20,2222222);
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
                out2 = new DataOutputStream(sc.getOutputStream());

                //Hay que poner nombres más bonitos a las variables
                Integer in1;
                Integer contador = 0;

                Character res = 'b';
                String finalString = "";

                do {
                    in1 = in.read();
            //        System.out.println(in1 + " Entrada \n");
                    res = (char) in1.intValue();
                    if (res == '{'){
                        contador++;
                        finalString+= res;
                    }else if(res == '}'){
                        contador--;
                        finalString+= res;
                    }
                    else {
                        finalString+= res;
                    }
                }
                while (!contador.equals(0));

                System.out.println(finalString);
                ventana.loadEventManagerJson(finalString);

//                Character letra = 'a';
//                String json = gson.toJson(jose);
               // out.println(ventana.getEventManagerJson());
                out.println(ventana.getEventManagerJson());
             //   out2.writeUTF(ventana.getEventManagerJson());
                sc.close();
                System.out.println("Cliente desconectado");

            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
