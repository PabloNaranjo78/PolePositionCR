package Eventos;
import Eventos.LinkedList.LinkedList;
import com.google.gson.Gson;
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

    private void addJugador(Integer nombre, Integer posX, Float km, Boolean shoot, Integer vidas,Integer puntos) {
        this.listaJugadores.addJugador(nombre, posX, km, shoot,vidas,puntos);
    }

    public void actualizarJugador(Integer nombre, Integer posX, Float km, Boolean shoot, Integer vidas, Integer puntos) {
        this.listaJugadores.actualizarJugador(nombre, posX, km, shoot,vidas,puntos);
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
//        String resultado = "{" + listaJugadores.toJson() +
//                "\"Trubo\":{\"activo\":" + turbo.getActivo() + ",\"kilometro\":" + turbo.getKilometro() + "}," +
//                "\"Disparo\":{activo:" + disparo.getActivo() + ",\"kilometro\":" + disparo.getKilometro() + "}," +
//                "\"Vida\":{\"activo\":" + vida.getActivo() + ",\"kilometro\":" + vida.getKilometro() + "}," +
//                "\"Hueco\":{\"activo\":" + hueco.getActivo() + ",\"kilometro\":" + hueco.getKilometro() + "}" + "}";
        Gson gson = new Gson();
        String resultado = gson.toJson(this);
        return resultado;
    }

    public void loadFromJson(String json) {

        Integer posXtemp = 0;
        Float kmtemp = 0.0f;
        Boolean shoottemp = false;
        Integer vidastemp = 0;
        Integer puntostemp = 0;

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
                    if (entry2.getKey().equals("Disparo")) {
                        shoottemp = entry2.getValue().getAsBoolean();
                    }
                    if (entry2.getKey().equals("vidas")) {
                        vidastemp = entry2.getValue().getAsInt();
                    }
                    if (entry2.getKey().equals("puntos")) {
                        puntostemp = entry2.getValue().getAsInt();
                    }

                }
                this.actualizarJugador(Integer.parseInt(entry.getKey()), posXtemp, kmtemp, shoottemp, vidastemp,puntostemp);
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
