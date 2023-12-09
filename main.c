//
//  main.c
//  5220505043ma
//
//  Created by mavlyuda almazova on 10.12.2023.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void) {
  char *metin;
  int anahtar;

  // Anahtarı alın.
  printf("Anahtarı girin: ");
  scanf("%d", &anahtar);

  // Dosyayı aç.
  FILE *dosya = fopen("input.txt", "r");
  if (dosya == NULL) {
    printf("Dosya açılamadı.");
    return 1;
  }

  // Dosyayı oku.
  metin = malloc(sizeof(char) * 1024);
  fgets(metin, sizeof(metin), dosya);

  // Dosyayı kapat.
  fclose(dosya);

  // Metni şifrele.
  for (int i = 0; metin[i] != '\0'; i++) {
    metin[i] = (metin[i] + anahtar) % 26;
  }

  // Şifrelenmiş metni kaydet.
  dosya = fopen("output.txt", "w");
  fprintf(dosya, "%s", metin);
  fclose(dosya);

  return 0;
}
