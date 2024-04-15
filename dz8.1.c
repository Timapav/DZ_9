#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	
	char *file = "output.txt";
	char text[] = "String from file\n";
	char buf[20];
	int fd, fd_in, fd_out;
	
	fd = open(file, O_WRONLY | O_CREAT, 0644); // Создание файла 
	fd_in = write(fd, text, sizeof(text) - 1); // Запись строки в файл
	close(fd); // Закрытие файла
	
	fd = open(file, O_RDONLY); // Открытие файла для чтения
	off_t size = lseek(fd, 0, SEEK_END);
	off_t pos = lseek(fd, -size, SEEK_END);
	ssize_t read_text = read(fd, buf, sizeof(buf)); // Чтение строки из файла
	write(1, buf, read_text); // Вывод строки в консоль
	close(fd); // Закрытие файла
	return 0; 
	
	

}






