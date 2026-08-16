IMAGE ?= melancholy

build: 
	docker build --no-cache -t $(IMAGE) .

clean:
	docker system prune -f

debug: 
	docker run -it $(IMAGE) bash

run:
	xhost +local:docker
	docker run -it \
		--net=host \
		-e DISPLAY=$(DISPLAY) \
		-v /tmp/.X11-unix:/tmp/.X11-unix \
		$(IMAGE)