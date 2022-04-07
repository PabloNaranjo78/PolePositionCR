package ServidorSockets;

import Eventos.Ventana;
import GsonManager.Informacion;
import com.google.gson.Gson;
import com.google.gson.stream.JsonToken;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.stream.Stream;

public class Servidor {
    public void iniciarServidor() {
        ServerSocket servidor = null;
        Socket sc = null; //Socket del cliente
        DataInputStream in;
        PrintStream out;

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

                //Ventana ventana = new Ventana();

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

                Character letra = 'a';
                String json = gson.toJson(jose);
                out.println(json);

                sc.close();
                System.out.println("Cliente desconectado");

            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
