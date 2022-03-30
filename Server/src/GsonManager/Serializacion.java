package GsonManager;
import com.google.gson.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class Serializacion {
    public static void main(String[] args) {
        Persona jan = new Persona("jan","Aguilar",21,118040303);

        Gson gson = new Gson();
        String json = gson.toJson(jan);
        System.out.println(json);

        Persona jan2 = gson.fromJson(json,Persona.class);
        jan2.printPersona();
    }
}

class Persona {
    private String nombre;
    private String apellido;
    private int edad;
    private int cedula;

    Persona(String nombre,String apellido, int edad,int cedula){
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
        this.cedula = cedula;

    }

    public void printPersona(){
        System.out.println("Hola me llamo "+this.nombre+" "+this.apellido+", tengo "+this.edad+" anos y mi cedula es "+
                this.cedula);

    }

}
