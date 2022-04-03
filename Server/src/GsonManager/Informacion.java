package GsonManager;

public class Informacion {
    private String nombre;
    private String apellido;
    private int edad;
    private int cedula;
    private String pack;

    public Informacion(String nombre, String apellido, int edad, int cedula) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
        this.cedula = cedula;
    }

    public void printInfo() {
        System.out.println("Hola me llamo " + nombre + " " + apellido + ", tengo "
                + edad + " anos y mi cedula es " + cedula);

    }

    public String paquete(){
        this.pack = "Hola me llamo " + nombre + " " + apellido + ", tengo "
                + edad + " anos y mi cedula es " + cedula;
        return pack;
    }
}
