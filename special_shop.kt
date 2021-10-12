



class Parabola(potCount: Long, xMult: Long, yMult: Long) {
    private val coeffA = xMult + yMult;
    private val coeffB = -2 * yMult * potCount;
    private val coeffC = potCount * potCount * yMult;

    fun minXCoord(): Long {
        val numerator = -1.0 * coeffB;
        val denominator = coeffA * 2.0;
        val result = numerator / denominator;
        return result.toLong();
    }

    fun solveAt(xCoord: Double): Long {
        val termA = xCoord * xCoord * coeffA;
        val termB = xCoord * coeffB;
        val termC = coeffC.doubleValue();
        val realResult = termA + termB + termC;
        return realResult.toLong();
    }
}


fun solveCase(potCount: Long, xMult: Long, yMult: Long): Long {
    val eq = Parabola(potCount, xMult, yMult);
    val optimal_a_pots = eq.minXCoord();
    val soln = eq.solveAt(optimal_a_pots);
    return soln.toBigInteger();
}

fun parseTestCase(): Unit {
    val caseParams = readLine()!!.split(" ");
    val potsToBuy = caseParams[0].toLong();
    val xCost = caseParams[1].toLong();
    val yCost = caseParams[2].toLong();
    val result = solveCase(potsToBuy, xCost, yCost);
    println(result);
}

fun main() {
    val caseCount = readLine()!!.toInt();

    for (i in 1..caseCount) {
        parseTestCase();
    }
}