
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
*
* @author Brenda GC
*/

public class Cliente extends Thread{
    static int TAM= 3500;
    int [] random = new int[TAM];
    int min;
    int max;
    int []ordenados;
    
    public void run()
    {
       ArrayList<Integer> cubeta = new ArrayList<>();
       
       for(int i=0;i<random.length;i++)
       {
           if(this.random[i] >= this.min && this.random[i] < this.max){
                cubeta.add(this.random[i]);
           }
       }
       /*System.out.println(this.max);
       System.out.println(k);
       System.out.println(cubeta.size());*/
       ordenados = new int[cubeta.size()];
       Integer [] enviar = cubeta.toArray(new Integer[cubeta.size()]);
       envia(enviar);
    }
    
    public void envia(Integer buf[])
    {
         try{
            Socket cl = new Socket("localhost",9999);
            System.out.println("Conexion establecida.. enviando datos..");
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            DataOutputStream dos = new DataOutputStream(baos);
            
            for(int i = 0;i < buf.length;i++){
                dos.writeInt(buf[i]);
                dos.flush();
            }
            
            byte[] buf2 = baos.toByteArray();
            BufferedOutputStream bos = new BufferedOutputStream(cl.getOutputStream());
            bos.write(buf2);
            bos.flush();
            
            byte [] buf3 = new byte[12000];
            BufferedInputStream bis = new BufferedInputStream(cl.getInputStream());
            DataInputStream dis = new DataInputStream(new ByteArrayInputStream(buf3));
            
            int k = bis.read(buf3);
            for(int i = 0; i < buf.length; i++){
                ordenados[i] = dis.readInt();
                //System.out.println(ordenados[i]);
            }
            
            bis.close();
            dis.close();
            bos.close();
            dos.close();
            baos.close();
            cl.close();
            System.out.println("Datos enviados...");
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }
    
    public void setRango(int min, int max){
        this.min = min;
        this.max = max;
    }
    
    public static void main(String[] args) throws Exception{
        Random r = new Random();
        int n;
        int random2[] = new int[TAM];
        
        for(int i=0;i<TAM;i++)
            random2[i] = Math.abs(r.nextInt()%1000);

        Scanner in = new Scanner(System.in);
        System.out.print("Numero de cubetas: ");
        n = in.nextInt();
        
        int div = 1000/n;
        int res = 1000%n;
        int cont = 0;
        Cliente [] ran = new Cliente[n];
        
        for(int i = 0; i < n; i++){
            ran[i] = new Cliente();
        }
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < TAM; j++){
                ran[i].random[j] = random2[j];
            }
      
        
        if(res != 0){
            for(int i=0;i<n;i++){
                if(i == n)
                    ran[i].setRango(cont*div, ((cont+1)*div)-1+res);
                else
                    ran[i].setRango(cont*div, ((cont+1)*div)-1);
                cont++;
            }
        }
        else{
            for(int i=0;i<n;i++){
                ran[i].setRango(cont*div, ((cont+1)*div)-1);
                cont++;
            }
        }
        
        Thread [] cubeta = new Thread[n];
        for(int i=0;i<n;i++){
            cubeta[i] = new Thread(ran[i]);
            cubeta[i].start();
        }
        
        for(int i=0;i<n;i++)
            cubeta[i].join();

        System.out.println("Numeros ordenados");
        for(int i = 0; i < n; i++){
            System.out.println("\nCubeta: "+(i+1)+"\n");
            for(int j = 1; j < ran[i].ordenados.length; j++)
            {
                if(ran[i].ordenados[j]<10)
                    System.out.print("00"+ran[i].ordenados[j]+" ");
                if(ran[i].ordenados[j]>9 && ran[i].ordenados[j]<100)
                    System.out.print("0"+ran[i].ordenados[j]+" ");
                if(ran[i].ordenados[j]>99)
                    System.out.print(ran[i].ordenados[j]+" ");
            }
            System.out.println("");
        }
           
    }
}