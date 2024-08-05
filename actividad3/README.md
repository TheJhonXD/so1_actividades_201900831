# Control de accesos

## Gestion de Usuarios

- **Creación de usuarios**

```bash
sudo adduser usuario1
sudo adduser usuario2
sudo adduser usuario3
```

- **Asignación de Contraseña**

```bash
sudo passwd usuario1
sudo passwd usuario2
sudo passwd usuario3
```

- **Información de Usuarios**

_Entrada:_

```bash
id usuario1
```

_Salida_:

```bash
uid=1001(usuario1) gid=1001(usuario1) groups=1001(usuario1),100(users)
```

- **Eliminación de Usuarios**

```bash
sudo userdel usuario3
```

## Gestión de Grupos

- **Creación de Grupos**

```bash
sudo groupadd grupo1
sudo groupadd grupo2
```

- **Agregar usuarios a Grupos**

```bash
sudo usermod -aG grupo1 usuario1
sudo usermod -aG grupo2 usuario2
```

- **Verificar membresía**

_Entrada_:

```bash
groups usuario1
groups usuario2
```

_Salida_:

```bash
usuario1 : usuario1 users grupo1
usuario2 : usuario2 users grupo2
```

- **Eliminar grupo**

```bash
sudo groupdel grupo2
```

## Gestión de Permisos

- **Creación de Archivos y Directorios**

```bash
sudo su usuario1
cd ~
echo "Hola mundo" > archivo1.txt
mkdir directorio1
cd directorio1/
echo "Hola mundo2" > archivo2.txt
```

- **Verificar permisos**

```bash
ls -l ~/archivo1.txt
ls -ld ~/directorio1
```
