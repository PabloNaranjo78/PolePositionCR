package GsonManager;

import com.google.gson.Gson;

public class Deserializacion {
    public static void main(String[] args) {
        Informacion jan = new Informacion("jan","Aguilar",21,118040303);

        Gson gson = new Gson();
        String json = gson.toJson(jan);

        Informacion jan2 = gson.fromJson(json,Informacion.class);
        jan2.printInfo();
    }
}

