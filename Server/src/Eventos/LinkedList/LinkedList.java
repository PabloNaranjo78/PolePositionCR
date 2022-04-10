package Eventos.LinkedList;

public class LinkedList {
    private Jugador head;

    public LinkedList(){
        head = null;
    }

    /***
     * Este metodo se encarga de actulizar la informacion de un jugador determinado
     * @param nombre es el numero de jugador en forma de Integer
     * @param nuevoPosX es la nueva posicion X del jugador
     * @param nuevoKm es la nueva posicion Y del jugador
     * @param nuevaShoot booleando que describe si el jugador esta disparando o no
     * @param nuevaVidas las vidas actuales que tiene el jugador
     * @param nuevaPuntos la nueva cantidad de puntos que posee el jugador
     */
    public void actualizarJugador(Integer nombre, Integer nuevoPosX, Float nuevoKm, Boolean nuevaShoot, Integer nuevaVidas, Integer nuevaPuntos){
        Jugador aux = head;
        Boolean encontrado = false;
        while(aux != null){
            if(aux.getNombre().equals(nombre)){
                aux.actualizar(nuevoPosX, nuevoKm, nuevaShoot, nuevaVidas,nuevaPuntos);
                encontrado = true;
            }
            aux = aux.getNext();
        }
        if (!encontrado){
            addJugador(nombre, nuevoPosX, nuevoKm, nuevaShoot,nuevaVidas, nuevaPuntos);
        }
    }

    /***
     * Este metodo se encarga de agregar un nuevo jugador
     * @param nombre nombre del jugador
     * @param posX posicion en X del jugador
     * @param km posicion en Y del jugador
     * @param shoot añade el estado del jugador
     * @param vidas añade el estado del jugador
     * @param puntos añade el estado del jugador
     */
    public void addJugador(Integer nombre, Integer posX, Float km, Boolean shoot, Integer vidas,Integer puntos){
        Jugador p = new Jugador(nombre, posX, km, shoot,vidas,puntos);
        addNode(p);
    }

    /***
     * Este metodo se encarga de crear un nuevo nodo
     * @param p es la cabeza de la lista
     */
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
