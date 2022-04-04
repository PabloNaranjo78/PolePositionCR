package Eventos;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Ventana extends JFrame implements ActionListener {

    JButton boton1;
    Ventana(){
        boton1 = new JButton();
        boton1.setBounds(10,10,200,200);
        boton1.addActionListener(this);

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        this.setSize(500,500);
        this.setVisible(true);
        this.add(boton1);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == boton1){
            System.out.println("Hola");
        }
    }
}
