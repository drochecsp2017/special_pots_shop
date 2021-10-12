
//import kotlin.io.readline;
import java.math.BigInteger;
import java.math.BigDecimal;
import java.math.MathContext;


class Parabola(potCount: BigInteger, xMult: BigInteger, yMult: BigInteger) {
    private val coeffA = xMult + yMult;
    private val coeffB = BigInteger.valueOf(-2) * yMult * potCount;
    private val coeffC = potCount.pow(2) * yMult;
    private val roundingMode = MathContext(0);

    fun minXCoord(): BigDecimal {
        val numerator = BigDecimal(-coeffB);
        val denominator = BigDecimal(coeffA * BigInteger.valueOf(2));
        val result = numerator.divide(denominator, roundingMode.getRoundingMode());
        return result.round(roundingMode);
    }

    fun solveAt(xCoord: BigDecimal): BigDecimal {
        val termA = xCoord.pow(2) * BigDecimal(coeffA)
        val termB = xCoord * BigDecimal(coeffB)
        val termC = BigDecimal(coeffC)
        val result = termA + termB + termC;
        return result.round(roundingMode);
    }
}


fun solveCase(potCount: BigInteger, xMult: BigInteger, yMult: BigInteger): BigInteger {
    val eq = Parabola(potCount, xMult, yMult);
    val optimal_a_pots = eq.minXCoord();
    val soln = eq.solveAt(optimal_a_pots);
    return soln.toBigInteger();
}

fun parseTestCase(): Unit {
    val caseParams = readLine()!!.split(" ");
    val potsToBuy = BigInteger(caseParams[0]);
    val xCost = BigInteger(caseParams[1]);
    val yCost = BigInteger(caseParams[2]);
    val result = solveCase(potsToBuy, xCost, yCost);
    println(result);
}

fun main() {
    val caseCount = readLine()!!.toInt();

    for (i in 1..caseCount) {
        parseTestCase();
    }
}