// ����������1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <glut.h>
#include "math.h"
#include "GLAux.h"

float m = 0, k = 1;
float m1, k1, d1;

float angle = 180;
float inten = 4;

unsigned int textures[1];

void LoadTextures()
{
AUX_RGBImageRec *texture1 = auxDIBImageLoadA("Planet(1).bmp");//��������� �������� ��� ������ ��������
glGenTextures(1, textures); //������������� ��������
glBindTexture(GL_TEXTURE_2D, textures[0]);//��������� ��������
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);// ��������� ��������
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//��������� ��������
glTexImage2D(GL_TEXTURE_2D, 0, 4, texture1->sizeX, texture1->sizeY, 0, GL_RGB,
GL_UNSIGNED_BYTE,texture1->data);//������������� ��������

}


void init(void);
void draw(void);
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("��������� ������ ����");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	LoadTextures();

	glEnable(GL_NORMALIZE);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_DEPTH_TEST);

	GLfloat light_position[] = { -1200 ,1200 , 0.0, 0.0 };
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1000, 1000, -500, 500, 1500, -1500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0.0, 0.0, 1366, 768);



	//�������
	GLUquadricObj *q = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	gluQuadricTexture(q, GL_TRUE);
	gluQuadricDrawStyle(q, GLU_FILL);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslatef(999, -499, 1499);
	glRotatef(angle*0.001, 0.0, 1000, 0.0);
	gluSphere(q, 450, 100, 100);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	float mat3_dif[] = { 1.0, 1.0, 1.0 };
	float mat3_amb[] = { 1.0, 1.0, 1.0 };
	float mat3_spec[] = { 1.0, 1.0, 1.0 };
	GLfloat mat3_em[] = { 0.2, 0.2 ,0.2, 1.0 };
	float mat3_shininess = 0;




	angle += 1;
	m -= 0.0002;
	//m -= 0.00001;
	m1 = 700 * sin(m);
	k1 = 1000 * cos(m);




	//�����

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat3_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat3_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat3_spec);
	glMaterialf(GL_FRONT, GL_SHININESS, mat3_shininess);
	//glMaterialfv(GL_FRONT, GL_EMISSION, mat3_em);

	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex3f(559, 56, 1499);
	glVertex3f(-395, -77, 1499);
	glVertex3f(59, -383, 1499);
	glVertex3f(-565, 454, 1499);
	glVertex3f(204, 120, 1499);
	glVertex3f(-798, -430, 1499);
	glVertex3f(123, -1, 1499);
	glVertex3f(-393, 111, 1499);
	glVertex3f(304, 109, 1499);
	glVertex3f(-679, -100, 1499);
	glVertex3f(139, -239, 1499);
	glVertex3f(-592, 109, 1499);
	glVertex3f(458, 120, 1499);
	glVertex3f(-485, -123, 1499);
	glVertex3f(978, -31, 1499);
	glVertex3f(-47, 211, 1499);
	glVertex3f(495, 485, 1499);
	glVertex3f(-1, -1, 1499);
	glVertex3f(-742, -123, 1499);
	glVertex3f(-32, 9, 1499);
	glVertex3f(543, -401, 1499);
	glVertex3f(-940, -13, 1499);
	glVertex3f(244, -25, 1499);
	glVertex3f(-564, 244, 1499);
	glVertex3f(149, 231, 1499);
	glVertex3f(-522, -483, 1499);
	glVertex3f(432, -76, 1499);
	glVertex3f(-568, 441, 1499);
	glVertex3f(954, 122, 1499);

	glVertex3f(-559, -56, 1499);
	glVertex3f(395, 77, 1499);
	glVertex3f(-59, 383, 1499);
	glVertex3f(4, -454, 1499);
	glVertex3f(-204, -120, 1499);
	glVertex3f(798, 430, 1499);
	glVertex3f(-123, -1, 1499);
	glVertex3f(-393, -111, 1499);
	glVertex3f(-304, -109, 1499);
	glVertex3f(679, 100, 1499);
	glVertex3f(-139, 239, 1499);
	glVertex3f(-592, -109, 1499);
	glVertex3f(-458, -120, 1499);
	glVertex3f(485, 123, 1499);
	glVertex3f(-978, 31, 1499);
	glVertex3f(47, -211, 1499);
	glVertex3f(-495, -485, 1499);
	glVertex3f(1, 1, 1499);
	glVertex3f(-742, 123, 1499);
	glVertex3f(32, -9, 1499);
	glVertex3f(-543, -401, 1499);
	glVertex3f(940, 13, 1499);
	glVertex3f(-244, 25, 1499);
	glVertex3f(564, 244, 1499);;
	glVertex3f(-149, -231, 1499);
	glVertex3f(522, 483, 1499);
	glVertex3f(-432, 76, 1499);
	glVertex3f(-568, 441, 1499);
	glVertex3f(-954, 122, 1499);
	glEnd();
	glPopMatrix();




	//�������

	glPushMatrix();

	glTranslatef(m1, 0.0, -k1);
	glRotatef(angle*0.0115, 0.0, 1000, 0.0);

	float mat1_dif[] = { 0.6, 0.6, 0.6 };
	float mat1_amb[] = { 0.6, 0.6, 0.6 };
	float mat1_spec[] = { 0.6, 0.6, 0.6 };
	float mat1_shininess = 100;


	glMaterialfv(GL_FRONT, GL_AMBIENT, mat1_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat1_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat1_spec);
	glMaterialf(GL_FRONT, GL_SHININESS, mat1_shininess);

	glColor3f(0.6, 0.6, 0.6);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	/*//������ 1.0 ������
	glBegin(GL_TRIANGLES);
	//������ �������
	glNormal3f(-50, -100, 0.0);
	glVertex3f(50, -25, 100); // ������ ������� �����
	glVertex3f(50, -25, -100); // ������ �������
	glVertex3f(-250, -12.5, 0.0); // ��������

	//������� ������� �������
	glNormal3f(0.0, 1.0, 1.0);
	glVertex3f(50, -25, 100); //������ �������
	glVertex3f(-250, -12.5, 0.0); // ��������
	glVertex3f(50, 12.5, 0.0); //������ �������

	//������� ������� �������
	glNormal3f(0.0, 1.0, -1.0);
	glVertex3f(50, 12.5, 0.0); //������ �������
	glVertex3f(-250, -12.5, 0.0); // ��������
	glVertex3f(50, -25, -100); //������ �������

	//������ �������
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(50, -25, 100); //������ �������
	glVertex3f(50, 12.5, 0.0); // �������
	glVertex3f(50, -25, -100); //������ �������
	glEnd();
	//������ 1.0 ����� */


	//������ 2.0 ������
	glBegin(GL_TRIANGLES);
	//������� ������ ������� �������
	glNormal3f(0.0, -1.0, -1.0);
	glVertex3f(50, -12.5, 100); //������ �������
	glVertex3f(-250, -12.5, 0.0); // ��������
	glVertex3f(50, -32.5, 0.0); //������ �������     37.5

	//������� ������ ������� �������
	glNormal3f(0.0, -1.0, 1.0);
	glVertex3f(50, -32.5, 0.0); //������ �������     37.5
	glVertex3f(-250, -12.5, 0.0); // ��������
	glVertex3f(50, -12.5, -100); //������ �������
	

	//������� ������� ������� �������
	glNormal3f(0.0, 1.0, 1.0);
	glVertex3f(50, -12.5, 100); //������ �������
	glVertex3f(-250, -12.5, 0.0); // ��������
	glVertex3f(50, 12.5, 0.0); //������ �������

	//������� ������� �������
	glNormal3f(0.0, 1.0, -1.0);
	glVertex3f(50, 12.5, 0.0); //������ �������
	glVertex3f(-250, -12.5, 0.0); // ��������
	glVertex3f(50, -12.5, -100); //������ �������
	glEnd();

	//������ �������
	glBegin(GL_POLYGON);
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(50, -12.5, 100); //������� �������
	glVertex3f(50, 12.5, 0.0); // �������
	glVertex3f(50, -12.5, -100); //������� �������
	glVertex3f(50, -32.5, 0);//������                 37.5
	glEnd();
	//������ 2.0 �����



	//������ ����� ����������
	glPushMatrix();
	glTranslatef(12.5, 0.0, 0.0);
	glScalef(75, 20, 50);
	glutSolidCube(1);
	glPopMatrix();


	//������� ������� ����������
	glPushMatrix();
	glTranslatef(20, 0.0, 0.0);
	glScalef(60, 30, 75);
	glutSolidCube(1);
	glPopMatrix();


	//������� ����� ����������
	glPushMatrix();
	glTranslatef(25, 0.0, 0.0);
	glScalef(50, 40, 50);
	glutSolidCube(1);
	glPopMatrix();


	//��������� �����

	//�������
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 1.0, 0.0);
	glVertex3f(25, 50, 10); //������� �����
	glVertex3f(40, 50, 10); //������� ������
	glVertex3f(40, 50, -10); //������� ������
	glVertex3f(25, 50, -10); //������� �����
	glEnd();

	//��������
	glBegin(GL_POLYGON);
	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(25, 20, 10); //������� ������
	glVertex3f(25, 50, 10); //������� �������
	glVertex3f(25, 50, -10); //������� ������� 
	glVertex3f(25, 20, -10); //������� ������
	glEnd();

	//������
	glBegin(GL_POLYGON);
	glNormal3f(10, 30, 0.0);
	glVertex3f(50, 20, 10); //������� ������
	glVertex3f(40, 50, 10); //������� �������
	glVertex3f(40, 50, -10); //������� ������� 
	glVertex3f(50, 20, -10); //������� ������
	glEnd();

	//������� �������
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(25, 20, 10); //������ �����
	glVertex3f(50, 20, 10); //������ ������
	glVertex3f(40, 50, 10); //������� ������ 
	glVertex3f(25, 50, 10); //������� �����
	glEnd();

	//������� �������
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(25, 20, -10); //������ �����
	glVertex3f(50, 20, -10); //������ ������
	glVertex3f(40, 50, -10); //������� ������ 
	glVertex3f(25, 50, -10); //������� �����
	glEnd();


	//�����
	glPushMatrix();
	glTranslatef(20, 42.5, 0.0);
	glScalef(20, 15, 50);
	glutSolidCube(1);
	glPopMatrix();

	//��������
	//������� ���
	glPushMatrix();
	glTranslatef(10, 52, 18);
	glutSolidSphere(4.5, 30, 30);
	glPopMatrix();

	//������� ���
	glPushMatrix();
	glTranslatef(10, 52, -18);
	glutSolidSphere(4.5, 30, 30);
	glPopMatrix();

	//�����
	glPushMatrix();
	glTranslatef(10, 51.5, 0.0);
	glScalef(8, 8, 12);
	glutSolidCube(1);
	glPopMatrix();


	//���������

	float mat2_dif[] = { 0.0, 1.0, 1.0,1.0 };
	float mat2_amb[] = { 0.0, 1.0, 1.0,1.0 };
	float mat2_spec[] = { 0.0, 1.0, 1.0,1.0 };
	float mat2_shininess = 100;

	GLfloat white_light1[] = { 0.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat2_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat2_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat2_spec);
	glMaterialf(GL_FRONT, GL_SHININESS, mat2_shininess);

	glColor3f(0.0, 1.0, 1.0);

	/*//��������� 1.0 ������
	glBegin(GL_POLYGON);
	GLint i, n;
	GLfloat y, z;
	n = 40;
	for (i = 1; i <= n; i++)
	{
		y = 8 * cos(2 * i*3.14 / n);
		z = 8 * sin(2 * i*3.14 / n);
		glVertex3f(51, y - 10, z + 26);
	}
	glEnd();

	GLfloat angle = 40;
	GLfloat light_position1[] = { 51, -10, 26, 10 };
	GLfloat light_position11[] = { 1.0, 0.0, 0.0, 10 };
	GLfloat light_position12[] = { 1.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position11); //����������� �����
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_position12); //��� ������ ����������� ����������
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, &angle);//���� ����� ���� � ���������� ����������

	glBegin(GL_POLYGON);
	n = 40;
	for (i = 1; i <= n; i++)
	{
		y = 8 * cos(2 * i*3.14 / n);
		z = 8 * sin(2 * i*3.14 / n);
		glVertex3f(51, y - 10, z);
	}
	glEnd();

	GLfloat light_position2[] = { 51, -10, 0, 10 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, white_light1);
	glLightfv(GL_LIGHT2, GL_SPECULAR, white_light1);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position11);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_position12);
	glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, &angle);

	glBegin(GL_POLYGON);
	n = 40;
	for (i = 1; i <= n; i++)
	{
		y = 8 * cos(2 * i*3.14 / n);
		z = 8 * sin(2 * i*3.14 / n);
		glVertex3f(51, y - 10, z - 26);
	}
	glEnd();

	GLfloat light_position3[] = { 51, -10, -26, 10 };
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, white_light1);
	glLightfv(GL_LIGHT3, GL_SPECULAR, white_light1);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position11);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_position12);
	glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, &angle);
	//��������� 2.0 �����*/

	//��������� 2.0 ������
	glBegin(GL_POLYGON);
	GLint i, n;
	GLfloat y, z;
	n = 40;
	for (i = 1; i <= n; i++)
	{
		y = 8 * cos(2 * i*3.14 / n);
		z = 8 * sin(2 * i*3.14 / n);
		glVertex3f(51, y - 13, z + 32);
	}
	glEnd();

	GLfloat angle = 40;
	GLfloat light_position1[] = { 51, -13, 32, 10 };
	GLfloat light_position11[] = { 1.0, 0.0, 0.0, 10 };
	GLfloat light_position12[] = { 1.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light1);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position11); //����������� �����
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_position12); //��� ������ ����������� ����������
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, &angle);//���� ����� ���� � ���������� ����������
	

	glBegin(GL_POLYGON);
	n = 40;
	for (i = 1; i <= n; i++)
	{
		y = 8 * cos(2 * i*3.14 / n);
		z = 8 * sin(2 * i*3.14 / n);
		glVertex3f(51, y - 13, z);
	}
	glEnd();

	GLfloat light_position2[] = { 51, -13, 0, 10 };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, white_light1);
	glLightfv(GL_LIGHT2, GL_SPECULAR, white_light1);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position11);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_position12);
	glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, &angle);

	glBegin(GL_POLYGON);
	n = 40;
	for (i = 1; i <= n; i++)
	{
		y = 8 * cos(2 * i*3.14 / n);
		z = 8 * sin(2 * i*3.14 / n);
		glVertex3f(51, y - 13, z - 32);
	}
	glEnd();

	GLfloat light_position3[] = { 51, -13, -32, 10 };
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, white_light1);
	glLightfv(GL_LIGHT3, GL_SPECULAR, white_light1);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position11);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_position12);
	glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, &angle);
	//��������� 2.0 �����



	glMaterialfv(GL_FRONT, GL_AMBIENT, mat1_amb);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat1_dif);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat1_spec);
	glMaterialf(GL_FRONT, GL_SHININESS, mat1_shininess);

	/*//��������� 1.0 �����������
	glPushMatrix();
	glTranslatef(50, -10, 26);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1, 1, 3);
	glutSolidTorus(3, 10, 3, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, -10, 0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1, 1, 3);
	glutSolidTorus(3, 10, 3, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, -10, -26);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1, 1, 3);
	glutSolidTorus(3, 10, 3, 20);
	glPopMatrix();
	//��������� 1.0 �����*/


	//��������� 2.0 �����������
	glPushMatrix();
	glTranslatef(50, -13, 32);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1, 1, 3);
	glutSolidTorus(3, 10, 3, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, -13, 0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1, 1, 3);
	glutSolidTorus(3, 10, 3, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(50, -13, -32);
	glRotatef(90, 0.0, 1.0, 0.0);
	glScalef(1, 1, 3);
	glutSolidTorus(3, 10, 3, 20);
	glPopMatrix();
	//��������� 2.0 �����


	glPopMatrix();

	glutSwapBuffers();
	glutPostRedisplay();
}

