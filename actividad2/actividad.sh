#!/bin/bash

# Verifica si se ha definido la variable GITHUB_USER
if [ -z "$GITHUB_USER" ]; then
  echo "La variable GITHUB_USER no está definida."
  exit 1
fi

API_GITHUB="https://api.github.com/users/${GITHUB_USER}"

#Conulsta de la API de GitHub
response=$(curl -X GET --header "Accept: */*" "$API_GITHUB")

#Obtener los datos necesario
user_id=$(echo "$response" | jq -r '.id')
created_at=$(echo "$response" | jq -r '.created_at')

message="Hola ${GITHUB_USER}. User ID: ${user_id}. Cuenta fue creada el: ${created_at}."

#Imprimo el mensaje
echo "$message"

#Creo el archivo
log_dir="/tmp/$(date +%Y-%m-%d)"
mkdir -p "$log_dir"

log_file="${log_dir}/saludos.log"

# Escribo el mensaje en el archivo
echo "$message" >> "$log_file"

echo "Archivo log escrito en ruta: $log_file"