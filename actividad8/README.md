# Primeros pasos con K8s

## 1. Instalación del ambiente local de Kubernetes (usando Minikube)

1. **Instalación de Minikube**:
   - Descargar e instalar Minikube según documentación oficial

2. **Iniciar Minikube**:
   ```bash
   minikube start
   ```

3. **Verificar el estado de Minikube**:
   ```bash
   minikube status
   ```

## 2. Desplegar un contenedor de Nginx en el cluster de Kubernetes local

1. **Crear un Deployment de Nginx**:
   - Archivo `deployment.yaml`:

     ```yaml
     apiVersion: apps/v1
     kind: Deployment
     metadata:
       name: nginx-deployment
     spec:
       replicas: 1
       selector:
         matchLabels:
           app: nginx
       template:
         metadata:
           labels:
             app: nginx
         spec:
           containers:
           - name: nginx
             image: nginx:latest
             ports:
             - containerPort: 80
     ```

2. **Aplicar el Deployment**:
   ```bash
   kubectl apply -f nginx-deployment.yaml
   ```

3. **Verificar que el Deployment está corriendo**:
   ```bash
   kubectl get deployments
   ```

4. **Crear un servicio para acceder a Nginx**:
   - Archivo `service.yaml`:

     ```yaml
     apiVersion: v1
     kind: Service
     metadata:
       name: nginx-service
     spec:
       selector:
         app: nginx
       ports:
         - protocol: TCP
           port: 80
           targetPort: 80
       type: NodePort
     ```

5. **Aplicar el servicio**:
   ```bash
   kubectl apply -f nginx-service.yaml
   ```

6. **Obtener la URL para acceder a Nginx**:
   ```bash
   minikube service nginx-service --url
   ```

## 3. Pregunta: ¿En un ambiente local de Kubernetes existen los nodos masters y workers, cómo es que esto funciona?

No se distingue explícitamente entre nodos maestros (masters) y nodos de trabajo (workers) de la misma manera que en un clúster Kubernetes completo.

Por defecto, Minikube configura un solo nodo que actúa como maestro y como worker. Este nodo único tiene todos los componentes necesarios de Kubernetes instalados (API Server, Scheduler, Controller Manager, y etcd para el plano de control, además de Kubelet y Container Runtime como servicios de infraestructura).

- **Funcionamiento**: Aunque no se divida en roles formales de master y worker, el nodo único de Minikube realiza todas las funciones esenciales de un clúster Kubernetes, incluyendo la programación de pods, la gestión de redes, el almacenamiento persistente y la orquestación de contenedores.
