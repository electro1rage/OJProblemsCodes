
import java.math.BigInteger;
import java.util.Scanner;


class Main {
    static boolean a[], b[], d[], A[], B[], C[];
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int K = 1;
		while (true) {
			BigInteger x, y, ans;
			x = in.nextBigInteger();
			y = in.nextBigInteger();
			
			if (x.compareTo(BigInteger.ZERO) == 0 && y.compareTo(x) == 0) break;
			if (K != 1) System.out.println();
			
			int n = Math.max(x.bitLength(), y.bitLength()), i, j, k, l;
			
			a = new boolean[n + 4];
			b = new boolean[n + 4];
			A = new boolean[n + 4];
			B = new boolean[n + 4];
			C = new boolean[n + 4];
			d = new boolean[n + 4];
			
			for (i = 0; i < n; ++i) a[i] = b[i] = A[i] = B[i] = false;
			
			i = n - 1;
			while (x.compareTo(BigInteger.ZERO) != 0) {
				if (x.mod(new BigInteger("2")).compareTo(BigInteger.ZERO) == 0) a[i] = false;
				else a[i] = true;
				x = x.divide(new BigInteger("2"));
				--i;
			}
			
			i = n - 1;
			while (y.compareTo(BigInteger.ZERO) != 0) {
				if (y.mod(new BigInteger("2")).compareTo(BigInteger.ZERO) == 0) d[i] = false;
				else d[i] = true;
				y = y.divide(new BigInteger("2"));
				--i;
			}
			
			for (i = 0; i < n; ++i) b[i] = a[i];
			
			b[0] = !b[0];
			b[1] = !b[1];
			B[0] = true;
			
			for (i = 1; i < n; ++i) {
				if (a[i - 1] != d[i - 1]) {
					a[i - 1] = !a[i - 1];
					a[i] = !a[i];
					a[i + 1] = !a[i + 1];
					A[i] = true;
				}
			}
			
			for (i = 1; i < n; ++i) {
				if (b[i - 1] != d[i - 1]) {
					b[i - 1] = !b[i - 1];
					b[i] = !b[i];
					b[i + 1] = !b[i + 1];
					B[i] = true;
				}
			}
			
			if (a[n - 1] == d[n - 1]) {
				for (i = 0; i < n; ++i) C[i] = A[i];
			} else if (b[n - 1] == d[n - 1]) {
				for (i = 0; i < n; ++i) C[i] = B[i];
			} else {
				System.out.println("Case Number " + K + ": impossible");
				++K;
				continue;
			}
			
			ans = BigInteger.ZERO;
			for (i = 0; i < n; ++i) {
				ans = ans.multiply(new BigInteger("2"));
				if (C[i]) ans = ans.add(BigInteger.ONE);
			}
			System.out.println("Case Number " + K + ": " + ans);
			++K;
		}
		in.close();
	}

}
