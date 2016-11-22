import java.math.BigInteger;
import java.util.*;

public class Main
{
	public static class RSA 
	{
		private BigInteger mod;
		private BigInteger exp;
		private BigInteger encryptedMessage;
	 
		public RSA () {}
	 
		public RSA (String text, String exp, String mod)
		{
			BigInteger temp = new BigInteger(text.replace(":", "").replaceFirst("0x", ""), 16);
			this.exp = new BigInteger(exp.replace(":", "").replaceFirst("0x", ""), 16);
			this.mod = new BigInteger(mod.replace(":", "").replaceFirst("0x", ""), 16);
			encryptedMessage = encrypt(temp);
		}
	 
		public BigInteger encrypt(BigInteger text)
		{
			return text.modPow(exp, mod);
		}
	 
		public BigInteger decrypt(BigInteger text, BigInteger d, BigInteger n)
		{
			return text.modPow(exp, mod);
		}

		public String getEncrypted()
		{
			return "0x" + encryptedMessage.toString(16);
		}
	}

	public static void main(String[] args) 
	{ 
 		String text = "0xABCDEF01234567890", exp = "0x10001", mod = "0x00:e2:2a:d6:cc:11:e6:a7:3f:c0:29";

 		RSA rsa = new RSA(text, exp, mod);
 		System.out.println(rsa.getEncrypted());
    }
}