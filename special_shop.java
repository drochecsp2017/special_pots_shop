
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.BigDecimal;

class TestClass {

    private static class Parabola {
        public Parabola(BigInteger numPots, BigInteger xMult, BigInteger yMult) {
            coeffA = xMult.add(yMult);
            coeffB = yMult.multiply(numPots).multiply(BigInteger.valueOf(-2));
            coeffC = numPots.pow(2).multiply(yMult);
        }

        public BigDecimal calcMin() {
            final BigInteger numerator = coeffB.multiply(BigInteger.valueOf(-1));
            final BigInteger denominator = coeffA.multiply(BigInteger.valueOf(2));
            final BigDecimal realNumerator = new BigDecimal(numerator);
            final BigDecimal realDenominator = new BigDecimal(denominator);
            final BigDecimal realResult = 
                realNumerator.divide(realDenominator, roundingMode.getRoundingMode());
            return realResult.round(roundingMode);
        }

        public BigDecimal calcAt(BigDecimal xCoord) {
            final BigDecimal aTerm = xCoord.pow(2).multiply(new BigDecimal(coeffA));
            final BigDecimal bTerm = xCoord.multiply(new BigDecimal(coeffB));
            final BigDecimal cTerm = new BigDecimal(coeffC);
            return aTerm.add(bTerm).add(cTerm).round(roundingMode);
        }

        private BigInteger coeffA;
        private BigInteger coeffB;
        private BigInteger coeffC;

        private MathContext roundingMode = new MathContext(0);
    }


    private static BigInteger solveCase(BigInteger numPots, BigInteger xMult, BigInteger yMult) {
        final Parabola eq = new Parabola(numPots, xMult, yMult);
        final BigDecimal optimalXCoord = eq.calcMin();
        final BigDecimal result = eq.calcAt(optimalXCoord);
        return result.toBigInteger();
    }

    private static void parseTestCase(String testCaseLine, BufferedWriter out) throws IOException {
        final String[] testCase = testCaseLine.trim().split(" ");
        final BigInteger pots_to_buy = new BigInteger(testCase[0]);
        final BigInteger x_cost = new BigInteger(testCase[1]);
        final BigInteger y_cost = new BigInteger(testCase[2]);
        final BigInteger result = solveCase(pots_to_buy, x_cost, y_cost);
        out.write(result.toString());
        out.newLine();
    }

    public static void main(String args[] ) throws Exception {
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final String numLinesLine = br.readLine().trim();
        final int numLines = Integer.parseInt(numLinesLine);

        final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        for(int i = 0; i < numLines; ++i) {
            parseTestCase(br.readLine(), out);
        }

        out.flush();
    }
}