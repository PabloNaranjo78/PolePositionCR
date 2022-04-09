package Eventos.LinkedList;

public class Jugador {
    private String nombre;
    private Integer posX;
    private Float km;
    private Boolean shoot;
    private Jugador nextJugador;

    public Jugador(String nombre, Integer posX, float km, boolean shoot){
        this.nombre = nombre;
        this.posX = posX;
        this.km = km;
        this.shoot = shoot;

    }

    public void actualizar( Integer posX, float km, boolean shoot){
        this.posX = posX;
        this.km = km;
        this.shoot = shoot;
    }

    public String getNombre(){
        return nombre;
    }
    public Integer getPosX(){
        return posX;
    }

    public float getKm(){
        return km;
    }

    public boolean getShoot(){
        return shoot;
    }

    public Jugador getNext(){
        return nextJugador;
    }

    public void setNext(Jugador nextJugador){
        this.nextJugador = nextJugador;
    }

    public String toString(){
        return "Jugador: " + "" + "\nposX: " + posX + "\nKm: " + km + "\nDisparo: " + shoot;
    }

    public String toJson(){
        return "{\"Jugador\":\"" + nombre + "\",\"posX\":\"" + posX + "\",\"Km\":" + km + ",\"Disparo\":\"" + shoot + "\"}";
    }

}
