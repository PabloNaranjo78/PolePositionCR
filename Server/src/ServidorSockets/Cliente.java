package ServidorSockets;

import GsonManager.Informacion;
import com.google.gson.Gson;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Cliente {
    public static void main(String[] args) {

        final String host = "127.0.0.1";
        final int puerto = 5000;
        DataInputStream in;
        DataOutputStream out;

        Informacion jose = new Informacion("jose","Sanchez",20,2222222);

        try {
            Socket sc = new Socket(host, puerto);

            in = new DataInputStream(sc.getInputStream());
            out = new DataOutputStream(sc.getOutputStream());

            Gson gson = new Gson();
            String json = gson.toJson(jose);

            out.writeUTF(json);
            //out.writeUTF("Hola mundo desde el cliente");

            String mensaje = in.readUTF();
            System.out.println(mensaje);

            sc.close();


        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
