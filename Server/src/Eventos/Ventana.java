package Eventos;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ventana extends JFrame implements ActionListener{

    JButton boton1, boton2, boton3, boton4;
    JTextField texto1, texto2, texto3, texto4;
    JLabel imagen1, imagen2, imagen3, imagen4;

    Turbo turboEvento = new Turbo();
    Disparo disparoEvento = new Disparo();
    Vida vidaEvento = new Vida();
    Hueco huecoEvento = new Hueco();

    public Ventana(){
        ImageIcon turbo = new ImageIcon(getClass().getResource("Turbo.png"));
        ImageIcon disparo = new ImageIcon(getClass().getResource("Disparo.png"));
        ImageIcon vida = new ImageIcon(getClass().getResource("Vida.png"));
        ImageIcon hueco = new ImageIcon(getClass().getResource("Hueco.png"));
        ImageIcon icono = new ImageIcon(getClass().getResource("Icono.png"));

        boton1 = new JButton();
        boton2 = new JButton();
        boton3 = new JButton();
        boton4 = new JButton();
        
        texto1 = new JTextField();
        texto2 = new JTextField();
        texto3 = new JTextField();
        texto4 = new JTextField();
        
        imagen1 = new JLabel(turbo);
        imagen2 = new JLabel(disparo);
        imagen3 = new JLabel(vida);
        imagen4 = new JLabel(hueco);
        
        boton1.setBounds(110,210,125,25);
        boton1.addActionListener(this);
        boton1.setText("TURBO");
        boton1.setFocusable(false);
        boton1.setHorizontalTextPosition(JButton.CENTER);
        boton1.setVerticalTextPosition(JButton.BOTTOM);
        boton1.setFont(new Font("Arial",Font.BOLD,20));
        boton1.setForeground(Color.BLACK);
        boton1.setBackground(Color.WHITE);
        boton1.setBorder(BorderFactory.createEtchedBorder());

        texto1.setBounds(10,210,90,25);
        texto1.setFont(new Font("Arial",Font.BOLD,20));

        imagen1.setBounds(10,10,225,190);

        boton2.setBounds(350,210,125,25);
        boton2.addActionListener(this);
        boton2.setText("DISPARO");
        boton2.setFocusable(false);
        boton2.setHorizontalTextPosition(JButton.CENTER);
        boton2.setVerticalTextPosition(JButton.BOTTOM);
        boton2.setFont(new Font("Arial",Font.BOLD,20));
        boton2.setForeground(Color.BLACK);
        boton2.setBackground(Color.WHITE);
        boton2.setBorder(BorderFactory.createEtchedBorder());

        texto2.setBounds(250,210,90,25);
        texto2.setFont(new Font("Arial",Font.BOLD,20));

        imagen2.setBounds(250,10,225,190);

        boton3.setBounds(110,450,125,25);
        boton3.addActionListener(this);
        boton3.setText("VIDA");
        boton3.setFocusable(false);
        boton3.setHorizontalTextPosition(JButton.CENTER);
        boton3.setVerticalTextPosition(JButton.BOTTOM);
        boton3.setFont(new Font("Arial",Font.BOLD,20));
        boton3.setForeground(Color.BLACK);
        boton3.setBackground(Color.WHITE);
        boton3.setBorder(BorderFactory.createEtchedBorder());

        texto3.setBounds(10,450,90,25);
        texto3.setFont(new Font("Arial",Font.BOLD,20));

        imagen3.setBounds(10,250,225,190);

        boton4.setBounds(350,450,125,25);
        boton4.addActionListener(this);//Expresion lambda
        boton4.setText("HUECO");
        boton4.setFocusable(false);
        boton4.setHorizontalTextPosition(JButton.CENTER);
        boton4.setVerticalTextPosition(JButton.BOTTOM);
        boton4.setFont(new Font("Arial",Font.BOLD,20));
        boton4.setForeground(Color.BLACK);
        boton4.setBackground(Color.WHITE);
        boton4.setBorder(BorderFactory.createEtchedBorder());

        texto4.setBounds(250,450,90,25);
        texto4.setFont(new Font("Arial",Font.BOLD,20));

        imagen4.setBounds(250,250,225,190);

        this.getContentPane().setBackground(Color.RED);
        this.setIconImage(icono.getImage());

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        this.setSize(500,525);
        this.setVisible(true);
        this.setResizable(false);
        this.add(boton1);
        this.add(boton2);
        this.add(boton3);
        this.add(boton4);
        this.add(texto1);
        this.add(texto2);
        this.add(texto3);
        this.add(texto4);
        this.add(imagen1);
        this.add(imagen2);
        this.add(imagen3);
        this.add(imagen4);
    }

    private Boolean comprobar(String cadena){
        Boolean resultado = null;
        try {
            Double.parseDouble(cadena);
            resultado = true;
        }catch(NumberFormatException e) {
            resultado = false;
        }
        return resultado;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource()==boton1){
            if (comprobar(texto1.getText())){
                turboEvento.setActivo(true);
                turboEvento.setKilometro(Float.valueOf(texto1.getText()));
                System.out.println(turboEvento.getKilometro());
                texto1.setText("");
            }else{
                texto1.setText("");
            }
        }
        if (e.getSource()==boton2){
            if (comprobar(texto2.getText())){
                disparoEvento.setActivo(true);
                disparoEvento.setKilometro(Float.valueOf(texto2.getText()));
                System.out.println(disparoEvento.getKilometro());
                texto2.setText("");
            }else{
                texto2.setText("");
            }
        }
        if (e.getSource()==boton3){
            if (comprobar(texto3.getText())){
                vidaEvento.setActivo(true);
                vidaEvento.setKilometro(Float.valueOf(texto3.getText()));
                System.out.println(vidaEvento.getKilometro());
                texto3.setText("");
            }else{
                texto3.setText("");
            }
        }
        if (e.getSource()==boton4){
            if (comprobar(texto4.getText())){
                huecoEvento.setActivo(true);
                huecoEvento.setKilometro(Float.valueOf(texto4.getText()));
                System.out.println(huecoEvento.getKilometro());
                texto4.setText("");
            }else{
                texto4.setText("");
            }
        }
    }
}
