package Eventos.LinkedList;

public class Jugador {
    private Integer nombre;
    private Integer posX;
    private Float km;
    private Boolean shoot;
    private Integer vidas;
    private Jugador nextJugador;

    public Jugador(Integer nombre, Integer posX, float km, boolean shoot, Integer vidas){
        this.nombre = nombre;
        this.posX = posX;
        this.km = km;
        this.shoot = shoot;
        this.vidas = vidas;

    }

    public void actualizar(Integer posX, float km, boolean shoot, Integer vidas){
        this.posX = posX;
        this.km = km;
        this.shoot = shoot;
        this.vidas = vidas;
    }

    public Integer getNombre(){
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
        return "Jugador: " + this.nombre + "\nposX: " + posX + "\nKm: " + km + "\nDisparo: " + shoot;
    }

    public String toJson(){
   //     return "{\"nombre\": " + this.nombre + ", \"posX\": " + posX + ", \"km\": " + km + ", \"shoot\": " + shoot + ", \"vidas\": " + vidas + "}";
        return "\"" +nombre+ "\"" + ":{\"posX\":" + posX + ",\"Km\":" + km + ",\"Disparo\":\"" + shoot + "\"" + ",\"vidas\":" + vidas + "}";
    }

}
