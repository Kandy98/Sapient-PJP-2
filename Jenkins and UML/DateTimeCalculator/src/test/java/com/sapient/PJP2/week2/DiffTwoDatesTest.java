package com.sapient.PJP2.week2;
import static org.junit.Assert.*;
import org.junit.Test;
import com.sapientPJP2.week2.RunnerCalculator.Date;
import com.sapientPJP2.week2.DiffTwoDates;

public class DiffTwoDatesTest {
    
	@Test
	public void test() {
		Date date1 = new Date(23,04,2020);
		Date date2 = new Date(12,04,2029);
		assertEquals(3276,DiffTwoDates.getDifference(date1,date2));
	}
}
