import java.math.BigInteger;
import java.util.*;

public class Main
{
	public static class RHO 
	{
		private BigInteger d;
		private BigInteger n;
		private BigInteger t;
		private BigInteger h;
		private BigInteger p;
		private BigInteger exp;
		private BigInteger q;
		private BigInteger phi;
		private BigInteger encryptedMessage;
		

		public RHO () {}
		public RHO (String n, String text, String exp)
		{
			this.n = new BigInteger(n.replace(":", "").replaceFirst("0x", ""), 16);
			encryptedMessage = new BigInteger(text.replace(":", "").replaceFirst("0x", ""), 16);
			this.exp = new BigInteger(exp.replace(":", "").replaceFirst("0x",""), 16);
			t = new BigInteger("2");
			h = new BigInteger("2");
			d = new BigInteger("1");
		}

		public BigInteger encryptedMessage()
		{
			return encryptedMessage;
		}

		public BigInteger f(BigInteger x)
		{
			return (x.pow(2).add(BigInteger.ONE)).mod(n);
		}

		public String getD()
		{
			return d.toString();
		}

		public String getN()
		{
			return n.toString();
		}

		public String getDecrypted()
		{
			return "0x" + encryptedMessage.modPow(d, n).toString(16);
		}

		public void factorization()
		{
			while (d.equals(BigInteger.ONE))
			{
				t = f(t);
				h = f(f(h));
				d = (t.subtract(h)).gcd(n);
			}
			p = d;
			q = n.divide(p);
			phi = (p.subtract(BigInteger.ONE)).multiply(q.subtract(BigInteger.ONE));
			d = exp.modInverse(phi);
		}

	}

	public static void main(String[] args) 
	{ 
 		RHO rho = new RHO("0x00:e2:2a:d6:cc:11:e6:a7:3f:c0:29", "0x378863b322ef6df303ca", "0x10001");
 		rho.factorization();
 		System.out.println(rho.getDecrypted());	
 		System.out.println(rho.getD());
 		System.out.println(rho.getN());		
    }
}