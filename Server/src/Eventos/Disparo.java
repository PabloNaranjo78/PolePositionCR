package Eventos;

public class Disparo {
    private Boolean activo;
    private Float kilometro;

    /***
     * Se encarga de inicializar los valores
     */
    public Disparo(){
        this.activo = false;
        this.kilometro = Float.valueOf(0);
    }

    /***
     * Se encarga de actualizar la variable estado
     * @param estado
     */
    public void setActivo(Boolean estado){
        this.activo = estado;
    }

    /***
     * Se encarga de actulizar la variable kilometro
     * @param kilometro_
     */
    public void setKilometro(Float kilometro_){
        this.kilometro = kilometro_;
    }

    /***
     * Retorna el estado de la variable activo
     * @return
     */
    public Boolean getActivo(){
        return activo;
    }

    /***
     * Retorna el kilometro en que se encuentra
     * @return
     */
    public Float getKilometro(){
        return kilometro;
    }
}
