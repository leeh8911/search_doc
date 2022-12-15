.PHONY: all
all: format test build debug static-test clean doc

.PHONY: docker-all
docker-all: docker-build docker-run

.PHONY: docker-build
docker-build:
	docker build -t search-doc .

.PHONY: docker-run
docker-run:
	docker run -it --rm -v ${PWD}:/develop search-doc

.PHONY: docker-push
docker-push:
	 docker tag search-doc leeh8911/search-doc
	 docker push leeh8911/search-doc

.PHONY: format
format:
	find src -iname *.h -o -iname *.cpp | xargs clang-format -i
	find test -iname *.h -o -iname *.cpp | xargs clang-format -i

.PHONY: build
build:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF .. && \
	make

.PHONY: run
run:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF -DOPTION_TEST_ALL=OFF ..&& \
	make &&\
	src/SEARCH_DOC_EXE
	
.PHONY: test-run
test-run:
	build/test/SEARCH_DOC_TEST

.PHONY: test
test:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF -DOPTION_TEST_ALL=OFF ..&& \
	make &&\
	test/SEARCH_DOC_TEST
.PHONY: test-run
test-run:
	build/test/SEARCH_DOC_TEST

.PHONY: test-all
test-all:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF -DOPTION_TEST_ALL=ON ..&& \
	make &&\
	test/SEARCH_DOC_TEST

.PHONY: test-all-report
test-all-report:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=OFF -DOPTION_TEST_ALL=ON ..&& \
	make &&\
	test/SEARCH_DOC_TEST --gtest_output=xml:test_result.xml

.PHONY: debug
debug:
	mkdir -p build
	cd build && \
	cmake -DCMAKE_BUILD_TYPE=debug -DCMAKE_CXX_CLANG_TIDY="clang-tidy;-checks=-*,google-readability-casting;-fix;-fix-errors;" .. &&\
	make

.PHONY: static-test
static-test:
	mkdir -p build/static-test
	cppcheck --cppcheck-build-dir=build/static-test src

.PHONY: clean
clean:
	rm -rf build

.PHONY: doc
doc:
	mkdir -p build
	cd build && \
	cmake -DOPTION_BUILD_DOCS=ON .. && \
	make docs