package Eventos;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ventana extends JFrame {

    JButton boton1,boton2;
    Ventana(){
        ImageIcon foto1 = new ImageIcon(getClass().getResource("Turbo.png"));

        boton1 = new JButton();
        boton2 = new JButton();

        boton1.setBounds(10,10,200,200);
        boton1.addActionListener(e -> System.out.println("TURBO"));//Expresion lambda
        boton1.setText("TURBO");
        boton1.setFocusable(false);
        boton1.setIcon(foto1);
        boton1.setHorizontalTextPosition(JButton.CENTER);
        boton1.setVerticalTextPosition(JButton.BOTTOM);
        boton1.setFont(new Font("Arial",Font.BOLD,20));
        boton1.setForeground(Color.BLACK);
        boton1.setBackground(Color.WHITE);
        boton1.setBorder(BorderFactory.createEtchedBorder());

        boton2.setBounds(260,10,200,200);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        this.setSize(500,500);
        this.setVisible(true);
        this.add(boton1);
        this.add(boton2);
    }

}
