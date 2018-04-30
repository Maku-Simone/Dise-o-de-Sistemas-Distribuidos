import java.net.*;
import java.io.*;
import java.util.*;
import static java.lang.Math.toIntExact;

public class ClienteUDP {
  // Los argumentos proporcionan el mensaje y el nombre del servidor
  public static void main(String args[]) {

    //getFourierList();

    try {
      DatagramSocket socketUDP = new DatagramSocket();
      //byte[] mensaje = args[0].getBytes();
      //String mensaje = args[1];
      //byte[] mensaje = serializeCoordenada(new Coordenada(5,6));
      InetAddress hostServidor = InetAddress.getByName(args[0]);
      int puertoServidor = 6789;

      // Construimos un datagrama para enviar el mensaje al servidor

      List<Coordenada> fourierList = getFourierList();

      for (int i=0; i<fourierList.size(); i++) {
        try        
        {
          Thread.sleep(4);
        } 
        catch(InterruptedException ex) 
        {
          Thread.currentThread().interrupt();
        }
        //System.out.println(fourierList.get(i).getY());
        double val = fourierList.get(i).getY();
        int ntgr = (int)val;
        String mensaje = String.valueOf(ntgr);
        DatagramPacket peticion =
        new DatagramPacket(mensaje.getBytes(), mensaje.getBytes().length, hostServidor,
                           puertoServidor);
        // Enviamos el datagrama
        socketUDP.send(peticion);
      }

      // Construimos el DatagramPacket que contendrá la respuesta
      /*byte[] bufer = new byte[1000];
      DatagramPacket respuesta =
        new DatagramPacket(bufer, bufer.length);
      socketUDP.receive(respuesta);*/

      //Coordenada c = getSerializableCoordenada(respuesta.getData());

      // Enviamos la respuesta del servidor a la salida estandar
      //System.out.println("x: " + c.getX());
      //System.out.println("y: " + c.getY());

      // Cerramos el socket
      socketUDP.close();

    } catch (SocketException e) {
      System.out.println("Socket: " + e.getMessage());
    } catch (IOException e) {
      System.out.println("IO: " + e.getMessage());
    }
  }

  public static List<Coordenada> getFourierList() {
    List<Coordenada> list = new ArrayList<>();
    int cont = 0;
    double cx = Math.PI/400;
    double ix = -Math.PI;

    while(ix<Math.PI) {
      list.add(new Coordenada(ix,1/Math.PI*(Math.sin(ix))*1500));
      //System.out.println(cont+" "+list.get(cont).getY()*1500);
      ix += cx;
      cont++;
    }

    System.out.println("TAM: "+list.size());
    return list;
  }


  public static Coordenada getSerializableCoordenada(byte[] data) {
    Coordenada c = null;
    try {
      InputStream myInputStream = new ByteArrayInputStream(data);
      ObjectInputStream in = new ObjectInputStream(myInputStream);
      c = (Coordenada) in.readObject();
      in.close();
    } catch (IOException i) {
      i.printStackTrace();
      return null;
    } catch (ClassNotFoundException ce) {
      System.out.println("Employee class not found");
      ce.printStackTrace();
      return null;
    }

    return c;
  }

  public static byte[] serializeCoordenada(Coordenada c) {
    ByteArrayOutputStream bos = new ByteArrayOutputStream();
    ObjectOutput out = null;
    byte[] yourBytes= null;

    try {
      out = new ObjectOutputStream(bos);
      out.writeObject(c);
      out.close();
      yourBytes = bos.toByteArray();
    } catch (IOException i) {
      i.printStackTrace();
    }

    return yourBytes;
  }
}