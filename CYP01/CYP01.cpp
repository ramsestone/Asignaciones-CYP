# include <stdio.h>

int main()
{
	int anchoDisp, altoDisp, x1, y1, x2, y2;
	float porcentajeCoordX, porcentajeCoordY, porcentajeAnchoElem, porcentajeAltoElem;

	scanf_s("%i %i %f %f %f %f", &anchoDisp, &altoDisp, &porcentajeCoordX, &porcentajeCoordY, &porcentajeAnchoElem, &porcentajeAltoElem);

	x1 = anchoDisp * porcentajeCoordX;
	y1 = altoDisp * porcentajeCoordY;
	x2 = x1 + (anchoDisp * porcentajeAnchoElem);
	y2 = y1 + (altoDisp * porcentajeAltoElem);

	printf("%i %i %5.2f %5.2f %5.2f %5.2f %i %i %i %i", anchoDisp, altoDisp, porcentajeCoordX, porcentajeCoordY, porcentajeAnchoElem, porcentajeAltoElem, x1, y1, x2, y2);

	return 0;
}