#include <stdio.h>

int task16() {
	float m_Dafna = 100;
	float m_Dadra = 100;
	
	int i=1;
	m_Dafna += 100 * .1;
	m_Dadra += m_Dadra * .05;
	
	printf("Year     Dafna     Dadra\n");
	while(m_Dadra < m_Dafna) {
		printf("%4d    %.2f    %.2f\n", i, m_Dadra, m_Dafna);
		m_Dafna += 100 * .1;
		m_Dadra += m_Dadra * .05;
		i++;
	}
		
	return 0;
}
