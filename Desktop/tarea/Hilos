import javax.sound.sampled.*;
import javax.swing.*;
import java.awt.*;
import java.io.*;

public class SonidoEImagen {

    public static void main(String[] args) {
        reproducirSonido("C:/Users/Administrador/Downloads/Segundo trabajo/cancion.wav");
        mostrarImagen("C:/Users/Administrador/Downloads/Segundo trabajo/imagen.jpg");
    }

    public static void reproducirSonido(String filePath) {
        try {
            File file = new File(filePath);
            AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(file);
            Clip clip = AudioSystem.getClip();
            clip.open(audioInputStream);
            clip.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


      public static void mostrarImagen(String filePath) {
        JFrame frame = new JFrame();
        JLabel label = new JLabel();
        ImageIcon icon = new ImageIcon(filePath);
        label.setIcon(icon);
        frame.getContentPane().add(label);
   frame.pack();
        frame.setVisible(true);
    }
}