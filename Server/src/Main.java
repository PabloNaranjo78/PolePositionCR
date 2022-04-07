import ServidorSockets.Servidor;

public class Main {
    public static void main(String[] args) {

        System.out.println("Hello World!");
        Servidor server = new Servidor();
        server.iniciarServidor();
    }
}
