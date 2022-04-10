package Eventos.LinkedList;

public class LinkedList {
    private Jugador head;

    public LinkedList(){
        head = null;
    }

    public void actualizarJugador(Integer nombre, Integer nuevoPosX, Float nuevoKm, Boolean nuevaShoot){
        Jugador aux = head;
        Boolean encontrado = false;
        while(aux != null){
            if(aux.getNombre().equals(nombre)){
                aux.actualizar(nuevoPosX, nuevoKm, nuevaShoot);
                encontrado = true;
            }
            aux = aux.getNext();
        }
        if (!encontrado){
            addJugador(nombre, nuevoPosX, nuevoKm, nuevaShoot);
        }
    }

    public void addJugador(Integer nombre, int posX, float km, boolean shoot){
        Jugador p = new Jugador(nombre, posX, km, shoot);
        addNode(p);
    }

    public void addNode(Jugador p){
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
            s += aux.toJson()+",";
            aux = aux.getNext();
        }
        return s;
    }
}
