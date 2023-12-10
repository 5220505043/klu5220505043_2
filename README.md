Şifreleme programı:
Kullanıcıdan bir anahtar kelimeyi girer:
   - `printf("Anahtarı girin: ");` ifadesiyle tamsayı olan anahtar kelimesini alıyoruz,
input.txt dosyasında hem okunur hem metni bir diziye kopyalıyoruz,
   - `FILE *dosya = fopen("input.txt", "r");` input.txt girdiğimizde okuma modunda açılıyor,
   - `metin = malloc(sizeof(char) * 1024);` 1024 karakter yazdığımızda bir bellek alanı ayarlanıyor,
   - `fgets(metin, sizeof(metin), dosya);` ifadesiyle dosyada metin bellek alanına kopyalanır,
   - `fclose(dosya);` ifadesiyle dosyayı kapatıyoruz.
bütün karakterler, alınan anahtar değeri kadar şifreleniyor:
   - `for (int i = 0; metin[i] != '\0'; i++) { metin[i] = (metin[i] + anahtar) % 26; }` bu ifadeyle her karakter, Sezar şifreleme yöntemine bağlı olarak belirtilen anahtar değeri kadar şifreleniyor.
     bu şifrelenmiş metini "output.txt" dosyasına yazdırıyoruz,
   - `dosya = fopen("output.txt", "w");`  "output.txt" dosyası yazma moduna açılıyor,
   - `fprintf(dosya, "%s", metin);` bu girdiğimiz yazıyla şifrelenmiş metin dosyaya yazılıyor,
   - `fclose(dosya);` yazdığımız ifedeyle dosya kapatılıyor.
     
Şifreleme işlemi sırasında kullanılan anahtar değeri ve şifrelenecek metin içeriğine bağlı olarak çıktı değişir. Örneğin, eğer "input.txt" dosyasında "Merhaba Dunya!" metni bulunuyorsa ve kullanıcı "anahtar" olarak 2 değerini girdiyse, çıktı şu olaçak:

`Ogtjdcb Fcpg!`
