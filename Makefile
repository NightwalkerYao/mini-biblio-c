.SILENT: build main add_adherent add_emprunt add_livre back_emprunt delete_adherent delete_livre find_adherent find_livre fort list_adherents list_emprunts list_livres seed sqlite3_client

PHONY: build main add_adherent add_emprunt add_livre back_emprunt delete_adherent delete_livre find_adherent find_livre fort list_adherents list_emprunts list_livres seed sqlite3_client help

help: ## Affiche l'aide
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

build: main add_adherent add_emprunt add_livre back_emprunt delete_adherent delete_livre find_adherent find_livre fort list_adherents list_emprunts list_livres seed sqlite3_client ## Construit le programme et produit un executable interactif : biblio
	gcc -o biblio "./tests/main.o" "./tests/add_adherent.o" "./tests/add_emprunt.o" "./tests/add_livre.o" \
	"./tests/back_emprunt.o" "./tests/delete_adherent.o" "./tests/delete_livre.o" "./tests/find_adherent.o" \
	"./tests/find_livre.o" "./tests/fort.o" "./tests/list_adherents.o" "./tests/list_emprunts.o" "./tests/list_livres.o" \
	"./tests/seed.o" "./tests/sqlite3_client.o" -lsqlite3 -lm;\
	rm ./tests/*.o;\
	echo "Terminé !"

sqlite3_client: ## Génère le fichier objet tests/sqlite3_client.o
	gcc -o "./tests/sqlite3_client.o" -c "./lib/sqlite3_client.c" -lsqlite3

seed: ## Génère le fichier objet tests/seed.o
	gcc -o "./tests/seed.o" -c "./lib/seed.c" -lsqlite3

list_livres: ## Génère le fichier objet tests/list_livres.o
	gcc -o "./tests/list_livres.o" -c "./lib/list_livres.c" -lsqlite3

list_emprunts: ## Génère le fichier objet tests/list_emprunts.o
	gcc -o "./tests/list_emprunts.o" -c "./lib/list_emprunts.c" -lsqlite3

list_adherents: ## Génère le fichier objet tests/list_adherents.o
	gcc -o "./tests/list_adherents.o" -c "./lib/list_adherents.c" -lsqlite3

fort: ## Génère le fichier objet tests/fort.o
	gcc -o "./tests/fort.o" -c "./lib/fort.c" -lsqlite3

find_livre: ## Génère le fichier objet tests/find_livre.o
	gcc -o "./tests/find_livre.o" -c "./lib/find_livre.c" -lsqlite3

find_adherent: ## Génère le fichier objet tests/find_adherent.o
	gcc -o "./tests/find_adherent.o" -c "./lib/find_adherent.c" -lsqlite3

delete_livre: ## Génère le fichier objet tests/delete_livre.o
	gcc -o "./tests/delete_livre.o" -c "./lib/delete_livre.c" -lsqlite3

delete_adherent: ## Génère le fichier objet tests/delete_adherent.o
	gcc -o "./tests/delete_adherent.o" -c "./lib/delete_adherent.c" -lsqlite3

back_emprunt: ## Génère le fichier objet tests/back_emprunt.o
	gcc -o "./tests/back_emprunt.o" -c "./lib/back_emprunt.c" -lsqlite3

add_livre: ## Génère le fichier objet tests/add_livre.o
	gcc -o "./tests/add_livre.o" -c "./lib/add_livre.c" -lsqlite3

add_emprunt: ## Génère le fichier objet tests/add_emprunt.o
	gcc -o "./tests/add_emprunt.o" -c "./lib/add_emprunt.c" -lsqlite3

add_adherent: ## Génère le fichier objet tests/add_adherent.o
	gcc -o "./tests/add_adherent.o" -c "./lib/add_adherent.c" -lsqlite3

main: ## Génère le fichier objet tests/main.o
	(ls "./tests/main.o" >> /dev/null 2>&1 && rm ./tests/*.o) || echo "Compilation en cours..."
	gcc -o "./tests/main.o" -c "./lib/main.c" -lsqlite3
