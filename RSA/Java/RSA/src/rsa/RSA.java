 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsa;

import static java.lang.Integer.min;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

/**
 *
 * @author weiss
 */

class ExtEuclides {
    BigInteger d, x, y;

    public ExtEuclides(BigInteger d, BigInteger x, BigInteger y) {
        this.d = d;
        this.x = x;
        this.y = y;
    }
    
    @Override
    public String toString (){
        return (new String("D: " + this.d + " X: " + this.x + " Y: " + this.y));
    }
}

class PublicKey {
    BigInteger e, n;

    public PublicKey(BigInteger e, BigInteger n) {
        this.e = e;
        this.n = n;
    }
    
    @Override
    public String toString(){
        return (new String("E: " + this.e + " N: " + this.n));
    }
    
}

class PrivateKey{
    BigInteger d, n;

    public PrivateKey(BigInteger d, BigInteger n){
        this.d = d;
        this.n = n;
    }
    
    @Override
    public String toString(){
        return (new String("D: " + this.d + " N: " + this.n));
    }
}

public class RSA {
    
    public static BigInteger expModular (BigInteger base, BigInteger exp, BigInteger mod){
        BigInteger res = BigInteger.ONE;
        while(exp.compareTo(BigInteger.ZERO) == 1){
            if(exp.mod(new BigInteger("2")).compareTo(BigInteger.ONE) == 0){
                res = res.multiply(base).mod(mod);
            }
            base = base.multiply(base).mod(mod);
            exp = exp.divide(new BigInteger("2"));
        }
        return res;
    }
    
    public static BigInteger euclides (BigInteger a, BigInteger b){
        if(b.compareTo(BigInteger.ZERO) == 0){
            return a;
        }
        return euclides(b, a.mod(b));
    }
    
    public static ExtEuclides extEuclides (BigInteger a, BigInteger b){
        if(b.compareTo(BigInteger.ZERO) == 0){
            return (new ExtEuclides(a, BigInteger.ONE, BigInteger.ZERO));
        }
        ExtEuclides tmp = extEuclides(b, a.mod(b));
        ExtEuclides res = new ExtEuclides(tmp.d, tmp.y, tmp.x.subtract(a.divide(b).multiply(tmp.y)));
        return res;
    }
    
    public static boolean witness(BigInteger candidato){
        Random rand = new Random();
        BigInteger bigRandom = new BigInteger(candidato.bitLength(), rand);
        bigRandom = bigRandom.min(candidato.subtract(BigInteger.ONE));
        bigRandom = bigRandom.max(new BigInteger("2"));
        BigInteger res = expModular(bigRandom, candidato.subtract(BigInteger.ONE), candidato);
        if(res.compareTo(BigInteger.ONE) == 0){
            return true;
        }
        return false;
    }
    
    public static boolean fermat(BigInteger candidato, int tentativas){
        for(int i = 0; i < tentativas; i++){
            if(!witness(candidato)){
                return false;
            }
        }        
        return true;
    }
    
    public static BigInteger modLinSolver(BigInteger a, BigInteger b, BigInteger n){
        ExtEuclides ret = extEuclides(a, n);
        BigInteger x0 = null;
        if(b.mod(ret.d).compareTo(BigInteger.ZERO) == 0){
            x0 = ret.x.multiply(b.divide(ret.d)).mod(n);
        }
        return x0;
    }
    
    public static BigInteger[] PQ(int numBits){
        //numBits /= 2;
        BigInteger[] ret = new BigInteger[2];
        Random rand = new Random();
        boolean flag = false;
        while(!flag){
            ret[0] = new BigInteger(numBits, rand);
            if(fermat(ret[0], 100) == true && ret[0].compareTo(BigInteger.ONE) == 1){
                flag = true;
            }
        }
        flag = false;
        while(!flag){
            ret[1] = new BigInteger(numBits, rand);
            if(fermat(ret[1], 100) == true && ret[1].compareTo(BigInteger.ONE) == 1 && euclides(ret[0], ret[1]).compareTo(BigInteger.ONE) == 0){
                flag = true;
            }
        }
        return ret;
    }
    
    public static ArrayList<Integer> crivo(int limite){
        if(limite < 0){
            limite = 5000000;
        }
        ArrayList<Integer> primos = new ArrayList<>();
        boolean[] ehPrimo = new boolean[limite + 5];
        Arrays.fill(ehPrimo, true);
        
        primos.add(new Integer(2));
        ehPrimo[0] = ehPrimo[1] = false;
        for(int i = 4; i <= limite; i += 2){
            ehPrimo[i] = false;
        }
        for(long i = 3; i <= limite; i += 2){
            if(ehPrimo[(int)i]){
                primos.add(new Integer((int)i));
                for(long j =  i * i; j <= limite; j += i){
                    ehPrimo[(int)j] = false;
                }
            }
        }
        return primos;
    }
    
    public static PublicKey geraPublicKey(BigInteger p, BigInteger q){
        BigInteger n = p.multiply(q);
        BigInteger m = (p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE)));
        boolean flag = false;
        ArrayList<Integer> primos = crivo(min(5000000, m.intValue()));
        
        Random rand = new Random();
        
        BigInteger e = new BigInteger("65537");
        
//        while(true){
//            e = new BigInteger(primos.get(rand.nextInt(primos.size() - 1)).toString());
//            if(euclides(e, m).compareTo(BigInteger.ONE) == 0){
//                break;
//            }
//        }
        
        return new PublicKey(e, n);
    }
    
    public static PrivateKey geraPrivateKey(BigInteger e, BigInteger p, BigInteger q){
        BigInteger n = p.multiply(q);
        BigInteger m = (p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE)));
        BigInteger d = modLinSolver(e, BigInteger.ONE, m);
        return new PrivateKey(d, n);
    }
    
    public static ArrayList<BigInteger> calcNumBloco(String msg, BigInteger n, int numBloco){
        boolean flag = false;
        ArrayList<BigInteger> ret = new ArrayList<>();
        while(numBloco > 1){
            flag = true;
            ret.clear();
            for(int j = 0; j < msg.length(); j += numBloco){
                String res = "";
                for(int i = 0; i + j < msg.length() && i < numBloco; i++){
                    String tmp = Integer.toBinaryString((int)msg.charAt(i + j));
                    while(tmp.length() != 8){
                        tmp = "0" + tmp;
                    }
                    res += tmp;
                }
                while(res.length() != 8 * numBloco){
                    res += "0";
                }
                BigInteger tot = new BigInteger(res, 2);
                if(tot.compareTo(n) == 1){
                    flag = false;
                } else {
                    ret.add(tot);
                }
            }
            if(flag){
                return ret;
            }
            numBloco--;
        }
        return ret;
    }
    
    public static ArrayList<BigInteger> criptografa(String msg, PublicKey pkey, int numBloco){
        ArrayList<BigInteger> blocos = calcNumBloco(msg, pkey.n, numBloco);
        ArrayList<BigInteger> msgEncryp = new ArrayList<>();
        for(BigInteger b : blocos){
            msgEncryp.add(expModular(b, pkey.e, pkey.n));
        }
        return msgEncryp;
    }
    
    public static String descriptografa(ArrayList<BigInteger> msgEncryp, PrivateKey pkey){
        String res = "";
        for(BigInteger b : msgEncryp){
            BigInteger desc = expModular(b, pkey.d, pkey.n);
            String msgBinary = desc.toString(2);
            while(msgBinary.length() % 8 != 0){
                msgBinary = "0" + msgBinary;
            }
            for(int i = 0; i < msgBinary.length(); i += 8){
                String tmp = "";
                for(int j = 0; i + j < msgBinary.length() && j < 8; j++){
                    tmp += msgBinary.charAt(i + j);
                }
                int value = Integer.parseInt(tmp, 2);
                if(value > 0){
                    res += (char)(value);
                }
            }
        }
        return res;
    }
    
    public static void breakCrypt(PublicKey pkey){
        for(BigInteger p = new BigInteger("2"); p.compareTo(pkey.n) == -1; p = p.add(BigInteger.ONE)){
            if(pkey.n.mod(p) == BigInteger.ZERO){
                BigInteger q = pkey.n.divide(p);
                if(fermat(p, 100) && fermat(q, 100)){
                    BigInteger m = (p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE)));
                    if(euclides(pkey.e, m).equals(BigInteger.ONE)){
                        System.out.println("Quebrado!!! P: " + p + " Q: " + q);
                        break;
                    }
                }
            }
        }
    } 
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
//        System.out.println("Expo modular 2^10: " + expModular(new BigInteger("2"), new BigInteger("10"), new BigInteger("10000000007")));
//        System.out.println("Euclides 128 64: " + euclides(new BigInteger("128"), new BigInteger("64")));
//        ExtEuclides teste = extEuclides(new BigInteger("1914"), new BigInteger("899"));
//        System.out.println("ExtEuclides 1914 e 899: " + teste);
//        System.out.println("Fermat para 1000000007: " + fermat(new BigInteger("1000000011"), 100));
//        System.out.println("ModLinSolve 227 e 198640: " + modLinSolver(new BigInteger("227"), BigInteger.ONE, new BigInteger("198640")));
//        BigInteger[] ret = PQ(64);
//        System.out.println("Primo 1: " + ret[0] + " Primo 2: " + ret[1]);
//        
//        PublicKey pubKey = geraPublicKey(ret[0], ret[1]);
//        System.out.println(pubKey);
//        PrivateKey privKey = geraPrivateKey(pubKey.e, ret[0], ret[1]);
//        System.out.println(privKey);
//        BigInteger tmp = expModular(new BigInteger("123456789"), pubKey.e, pubKey.n);
//        System.out.println(tmp);
//        BigInteger retorno = expModular(tmp, privKey.d, privKey.n);
//        System.out.println(retorno);
        
//        PublicKey tt = geraPublicKey(new BigInteger("521"), new BigInteger("383"));
//        tt.e = new BigInteger("227");
//        System.out.println(tt);
//        PrivateKey ttt = geraPrivateKey(tt.e, new BigInteger("521"), new BigInteger("383"));
//        System.out.println(ttt);
//        PublicKey t = new PublicKey(new BigInteger("227"), new BigInteger("199543"));
//        PrivateKey pt = new PrivateKey(new BigInteger("105883"), new BigInteger("199543"));
//        BigInteger tmp = expModular(new BigInteger("113"), t.e, t.n);
//        System.out.println(tmp);
//        BigInteger retorno = expModular(tmp, pt.d, pt.n);
//        System.out.println(retorno);

          BigInteger[] pq = PQ(32);
          PublicKey pubKey = geraPublicKey(pq[0], pq[1]);
          PrivateKey privKey = geraPrivateKey(pubKey.e, pq[0], pq[1]);
          String msg = "RSA é legal mas é meio chato de implementar pq na implementação padrão as frases não podem ser muito compridas, requerindo como \"workaround\" a divisão do conteúdo em blocos de tamanho menor do que o tamanho da chave de criptografia.";
          ArrayList<BigInteger> msgEncryp = criptografa(msg, pubKey, 10);
          String volta = descriptografa(msgEncryp, privKey);
          
          System.out.println("Poriginal: " + pq[0] + "  Qoriginal: " + pq[1]);
          
          breakCrypt(pubKey);
          
          System.out.println(volta);
        
    }
    
}
