package ServidorSockets;

import Eventos.Ventana;

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



        try {
            servidor = new ServerSocket(puerto);
            System.out.println("Servidor iniciado");

            while (true){
                sc = servidor.accept();
                System.out.println("Cliente conectado");

                in = new DataInputStream(sc.getInputStream());
                out = new PrintStream(sc.getOutputStream());

                Integer in1;
                Integer contador = 0;

                Character res = 'b';
                String finalString = "";

                do {
                    in1 = in.read();
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

                out.println(ventana.getEventManagerJson());
                sc.close();
                System.out.println("Cliente desconectado");

            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
