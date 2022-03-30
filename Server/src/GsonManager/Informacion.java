package GsonManager;

public class Informacion {
    private String nombre;
    private String apellido;
    private int edad;
    private int cedula;

    Informacion(String nombre,String apellido, int edad,int cedula) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.edad = edad;
        this.cedula = cedula;
    }

        public void printInfo(){
            System.out.println("Hola me llamo "+this.nombre+" "+this.apellido+", tengo "+this.edad+" anos y mi cedula es "+
                    this.cedula);

        }
}
