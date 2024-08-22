# Servicio de Saludo

Creación un servicio en Linux utilizando `systemd` que ejecuta un script que imprime un saludo y la fecha actual infinitamente con una pausa de un segundo.

## Instalación

1. **Creción el archivo de servicio**:

   Creo archivo de servicio en `/etc/systemd/system/saludo.service`:

   ```ini
   [Unit]
   Description=Servicio que saluda y da la fecha actual

   [Service]
   ExecStart=/usr/local/bin/script.sh
   Restart=always
   RestartSec=1

   [Install]
   WantedBy=multi-user.target
   ```

2. **Habilitar e iniciar el servicio**:

   ```bash
   sudo systemctl enable script.service
   sudo systemctl start script.service
   ```

## Verificación

Para verificar que el servicio esté corriendo:

```bash
sudo systemctl status script.service
```

## Ver logs

```bash
sudo journalctl -u saludo.service -f
```

## Quitar el servicio

```bash
sudo systemctl stop saludo.service
sudo systemctl disable saludo.service

```
