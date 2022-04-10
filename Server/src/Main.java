import Eventos.EventManager;
import Eventos.LinkedList.LinkedList;
import ServidorSockets.Servidor;
import com.google.gson.Gson;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.util.Map;
import java.util.Set;

public class Main {
    public static void main(String[] args) {

//        System.out.println("Hello World!");
//        Servidor server = new Servidor();
//        server.iniciarServidor();
//        LinkedList lista = new LinkedList();
//        lista.addJugador(1,34,22.2f,true);
//        lista.addJugador(2,364,221.2f,true);
//        lista.actualizarJugador(1,366,252.2f,true);
//
//        System.out.println(lista.toString());

        EventManager eventManager = new EventManager();
        eventManager.addJugador(1,34,22.2f,true);
        eventManager.addJugador(2,34,22.2f,true);
        eventManager.agregarTurbo(2.2f);
        String jsonText = eventManager.getJsonEvent();
    //    System.out.println(jsonText);

        EventManager eventManager2 = new EventManager();

        eventManager2.loadFromJson(jsonText);

        System.out.println(eventManager2.getJsonEvent());


      //  System.out.println(lista.toJson());
    }
}
