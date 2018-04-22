import java.util.*;

public class Cadenotas
  {
    public static void main(String args[])
      {
        String cad;
        cad = rellenarCadena();
        /*for(int i = 0; i < cad.length(); i++)
          {
            System.out.print(cad.charAt(i));
          }*/
        busca(cad);
      }
    public static String rellenarCadena()
      {
          StringBuilder cadenota = new StringBuilder();
          int letrotas; //10M
          Scanner sc = new Scanner(System.in);
          letrotas = sc.nextInt();
          for(int i = 0; i < letrotas; i++)
            {
              for(int j = 0; j < 3; j++)
                {
                  Random rnd = new Random();
                  char c = (char) (rnd.nextInt(26) + 'A');
                  cadenota.append(c + "");
                }
              cadenota.append(" ");
            }
          return cadenota.toString();
      }
    public static void busca(String cad)
      {
        int apariciones = 0;
        for(int i = 0; i < cad.length() -4; i+=4)
          {
            String aux = cad.substring(i, i+3);
            if(aux.contains("IPN"))
              {
                apariciones++;
              }
          }
          System.out.println("Hay "+apariciones+" veces IPN");
      }
  }
