package Eventos;

public class Disparo {
    private Boolean activo;
    private Float kilometro;

    public Disparo(){
        this.activo = false;
        this.kilometro = Float.valueOf(0);
    }

    public void setActivo(Boolean estado){
        this.activo = estado;
    }

    public void setKilometro(Float kilometro_){
        this.kilometro = kilometro_;
    }

    public Boolean getActivo(){
        return activo;
    }

    public Float getKilometro(){
        return kilometro;
    }
}
