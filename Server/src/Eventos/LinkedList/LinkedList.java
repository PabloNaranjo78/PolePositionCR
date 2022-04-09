package Eventos.LinkedList;

public class LinkedList {
    private Jugador head;

    public LinkedList(){
        head = null;
    }

    public void actualizarJugador(String nombre, int nuevoPosX, float nuevoKm, boolean nuevaShoot){
        Jugador aux = head;
        while(aux != null){
            if(aux.getNombre().equals(nombre)){
                aux.actualizar(nuevoPosX, nuevoKm, nuevaShoot);
            }
            aux = aux.getNext();
        }
    }

    public void add(Jugador p){
        if(head == null){
            head = p;
        }else{
            Jugador aux = head;
            while(aux.getNext() != null){
                aux = aux.getNext();
            }
            aux.setNext(p);
        }
    }

    public String toString(){
        String s = "";
        Jugador aux = head;
        while(aux != null){
            s += aux.toString() + "\n";
            aux = aux.getNext();
        }
        return s;
    }

    public String toJson(){
        String s = "";
        Jugador aux = head;
        while(aux != null){
            s += aux.toJson() + "\n";
            aux = aux.getNext();
        }
        return s;
    }
}
