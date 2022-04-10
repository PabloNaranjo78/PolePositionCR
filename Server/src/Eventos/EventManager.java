package Eventos;
import Eventos.LinkedList.LinkedList;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.util.Map;
import java.util.Set;

public class EventManager {

    private Turbo turbo = new Turbo();
    private Disparo disparo = new Disparo();
    private Vida vida = new Vida();
    private Hueco hueco = new Hueco();
    private LinkedList listaJugadores = new LinkedList();

    public void addJugador(Integer nombre, Integer posX, Float km, Boolean shoot) {
        this.listaJugadores.addJugador(nombre, posX, km, shoot);
    }

    public void actualizarJugador(Integer nombre, Integer posX, Float km, Boolean shoot) {
        this.listaJugadores.actualizarJugador(nombre, posX, km, shoot);
    }

    public EventManager() {
    }

    void resetEvents() {
        turbo.setActivo(false);
        disparo.setActivo(false);
        vida.setActivo(false);
        hueco.setActivo(false);
    }

    public void agregarTurbo(Float kilometro) {
        turbo.setKilometro(kilometro);
        turbo.setActivo(true);
    }

    public void agregarDisparo(Float kilometro) {
        disparo.setKilometro(kilometro);
        disparo.setActivo(true);
    }

    public void agregarVida(Float kilometro) {
        vida.setKilometro(kilometro);
        vida.setActivo(true);
    }

    public void agregarHueco(Float kilometro) {
        hueco.setKilometro(kilometro);
        hueco.setActivo(true);
    }

    public String getJsonEvent() {
        String resultado = "{" + listaJugadores.toJson() + "Trubo:{activo:" + turbo.getActivo() + ", kilometro:" + turbo.getKilometro() + "}," +
                "Disparo:{activo:" + disparo.getActivo() + ", kilometro:" + disparo.getKilometro() + "}," +
                "Vida:{activo:" + vida.getActivo() + ", kilometro:" + vida.getKilometro() + "}," +
                "Hueco:{activo:" + hueco.getActivo() + ", kilometro:" + hueco.getKilometro() + "}" + "}";
        return resultado;
    }

    public void loadFromJson(String json) {

        int posXtemp = 0;
        float kmtemp = 0.0f;
        Boolean shoottemp = false;

        JsonParser parser = new JsonParser();
        JsonElement elemet = parser.parse(json);
        JsonObject obj = elemet.getAsJsonObject();
        Set<Map.Entry<String, JsonElement>> entrySet = obj.entrySet();
        for (Map.Entry<String, JsonElement> entry : entrySet) {
            if (entry.getKey().equals("0") || entry.getKey().equals("1") || entry.getKey().equals("2") || entry.getKey().equals("3")) {
                JsonObject obj2 = entry.getValue().getAsJsonObject();
                Set<Map.Entry<String, JsonElement>> entrySet2 = obj2.entrySet();
                for (Map.Entry<String, JsonElement> entry2 : entrySet2) {
                    if (entry2.getKey().equals("posX")) {
                        posXtemp = entry2.getValue().getAsInt();
                    }
                    if (entry2.getKey().equals("Km")) {
                        kmtemp = entry2.getValue().getAsFloat();
                    }
                    if (entry2.getKey().equals("shoot")) {
                        shoottemp = entry2.getValue().getAsBoolean();
                    }

                }
                this.actualizarJugador(Integer.parseInt(entry.getKey()), posXtemp, kmtemp, shoottemp);
            }
            if (entry.getKey().equals("Trubo")) {
                JsonObject obj2 = entry.getValue().getAsJsonObject();
                Set<Map.Entry<String, JsonElement>> entrySet2 = obj2.entrySet();
                for (Map.Entry<String, JsonElement> entry2 : entrySet2) {
                    if (entry2.getKey().equals("activo")) {
                        turbo.setActivo(entry2.getValue().getAsBoolean());
                    }
                    if (entry2.getKey().equals("kilometro")) {
                        turbo.setKilometro(entry2.getValue().getAsFloat());
                    }
                }
            }
            if (entry.getKey().equals("Disparo")) {
                JsonObject obj2 = entry.getValue().getAsJsonObject();
                Set<Map.Entry<String, JsonElement>> entrySet2 = obj2.entrySet();
                for (Map.Entry<String, JsonElement> entry2 : entrySet2) {
                    if (entry2.getKey().equals("activo")) {
                        disparo.setActivo(entry2.getValue().getAsBoolean());
                    }
                    if (entry2.getKey().equals("kilometro")) {
                        disparo.setKilometro(entry2.getValue().getAsFloat());
                    }
                }
            }
            if (entry.getKey().equals("Vida")) {
                JsonObject obj2 = entry.getValue().getAsJsonObject();
                Set<Map.Entry<String, JsonElement>> entrySet2 = obj2.entrySet();
                for (Map.Entry<String, JsonElement> entry2 : entrySet2) {
                    if (entry2.getKey().equals("activo")) {
                        vida.setActivo(entry2.getValue().getAsBoolean());
                    }
                    if (entry2.getKey().equals("kilometro")) {
                        vida.setKilometro(entry2.getValue().getAsFloat());
                    }
                }
            }
            if (entry.getKey().equals("Hueco")) {
                JsonObject obj2 = entry.getValue().getAsJsonObject();
                Set<Map.Entry<String, JsonElement>> entrySet2 = obj2.entrySet();
                for (Map.Entry<String, JsonElement> entry2 : entrySet2) {
                    if (entry2.getKey().equals("activo")) {
                        hueco.setActivo(entry2.getValue().getAsBoolean());
                    }
                    if (entry2.getKey().equals("kilometro")) {
                        hueco.setKilometro(entry2.getValue().getAsFloat());
                    }
                }
            }

        }
    }
}
