package GsonManager;

import com.google.gson.Gson;

public class Deserializacion {
    public void deserializar() {
        Informacion jan = new Informacion("jan","Aguilar",21,118040303);

        Gson gson = new Gson();
        String json = gson.toJson(jan);
        System.out.println(json);

        Informacion jan2 = gson.fromJson(json,Informacion.class);
        System.out.printf(jan2.paquete());
        //.printInfo();
    }
}

