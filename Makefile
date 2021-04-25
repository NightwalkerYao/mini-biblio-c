.SILENT: app main add_adherent add_emprunt add_livre back_emprunt delete_adherent delete_livre find_adherent find_livre fort list_adherents list_emprunts list_livres seed sqlite3_client

app: main add_adherent add_emprunt add_livre back_emprunt delete_adherent delete_livre find_adherent find_livre fort list_adherents list_emprunts list_livres seed sqlite3_client
	gcc -o app "./tests/main.o" "./tests/add_adherent.o" "./tests/add_emprunt.o" "./tests/add_livre.o" \
	"./tests/back_emprunt.o" "./tests/delete_adherent.o" "./tests/delete_livre.o" "./tests/find_adherent.o" \
	"./tests/find_livre.o" "./tests/fort.o" "./tests/list_adherents.o" "./tests/list_emprunts.o" "./tests/list_livres.o" \
	"./tests/seed.o" "./tests/sqlite3_client.o" -lsqlite3 -lm;\
	rm ./tests/*.o;\
	echo "Terminé !"

sqlite3_client:
	gcc -o "./tests/sqlite3_client.o" -c "./lib/sqlite3_client.c" -lsqlite3

seed:
	gcc -o "./tests/seed.o" -c "./lib/seed.c" -lsqlite3

list_livres:
	gcc -o "./tests/list_livres.o" -c "./lib/list_livres.c" -lsqlite3

list_emprunts:
	gcc -o "./tests/list_emprunts.o" -c "./lib/list_emprunts.c" -lsqlite3

list_adherents:
	gcc -o "./tests/list_adherents.o" -c "./lib/list_adherents.c" -lsqlite3

fort:
	gcc -o "./tests/fort.o" -c "./lib/fort.c" -lsqlite3

find_livre:
	gcc -o "./tests/find_livre.o" -c "./lib/find_livre.c" -lsqlite3

find_adherent:
	gcc -o "./tests/find_adherent.o" -c "./lib/find_adherent.c" -lsqlite3

delete_livre:
	gcc -o "./tests/delete_livre.o" -c "./lib/delete_livre.c" -lsqlite3

delete_adherent:
	gcc -o "./tests/delete_adherent.o" -c "./lib/delete_adherent.c" -lsqlite3

back_emprunt:
	gcc -o "./tests/back_emprunt.o" -c "./lib/back_emprunt.c" -lsqlite3

add_livre:
	gcc -o "./tests/add_livre.o" -c "./lib/add_livre.c" -lsqlite3

add_emprunt:
	gcc -o "./tests/add_emprunt.o" -c "./lib/add_emprunt.c" -lsqlite3

add_adherent:
	gcc -o "./tests/add_adherent.o" -c "./lib/add_adherent.c" -lsqlite3

main:
	(ls "./tests/main.o" >> /dev/null 2>&1 && rm ./tests/*.o) || echo "Compilation en cours..."
	gcc -o "./tests/main.o" -c main.c -lsqlite3
