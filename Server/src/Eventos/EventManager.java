package Eventos;

public class EventManager {

    private Turbo turbo = new Turbo();
    private Disparo disparo = new Disparo();
    private Vida vida = new Vida();
    private Hueco hueco = new Hueco();

    public EventManager() {
    }

    void resetEvents(){
        turbo.setActivo(false);
        disparo.setActivo(false);
        vida.setActivo(false);
        hueco.setActivo(false);
    }

    void agregarTurbo(Float kilometro){
        turbo.setKilometro(kilometro);
        turbo.setActivo(true);
    }

    void agregarDisparo(Float kilometro){
        disparo.setKilometro(kilometro);
        disparo.setActivo(true);
    }

    void agregarVida(Float kilometro){
        vida.setKilometro(kilometro);
        vida.setActivo(true);
    }

    void agregarHueco(Float kilometro){
        hueco.setKilometro(kilometro);
        hueco.setActivo(true);
    }

    String getJsonEvent(){
        String resultado = "{Trubo:{activo:"+turbo.getActivo()+", kilometro:"+turbo.getKilometro()+"},"+
                "Disparo:{activo:"+disparo.getActivo()+", kilometro:"+disparo.getKilometro()+"},"+
                "Vida:{activo:"+vida.getActivo()+", kilometro:"+vida.getKilometro()+"},"+
                "Hueco:{activo:"+hueco.getActivo()+", kilometro:"+hueco.getKilometro()+"}"+"}";
        return resultado;
    }
}
