package GsonManager;
import com.google.gson.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

class Persona {
    private String nombre;
    private String apellido;
    private int edad;
    private int a;

    Persona(String nombre, String apellido, int edad, int a){
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
        this.a = a;
    }
}

public class Serializacion {
    public static void main(String[] args) {
        Persona jan = new Persona("jan","Aguilar",21,118040303);

        Gson gson = new Gson();
        String json = gson.toJson(jan);
        System.out.println(json);
      //  Persona jan2 = gson.fromJson(json,Persona.class);
      //  jan2.printPersona();
    }
}

