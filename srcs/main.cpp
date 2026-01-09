#include <scop.hpp>
#include <Window.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // initialize window and GL context through Window helper
    Window window(SCR_WIDTH, SCR_HEIGHT, "SCOP");
    if (!window.isValid()) {
        return EXIT_FAILURE;
    }
    GLFWwindow* win = window.get();
    glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);

    // build and compile our shader program
    // ------------------------------------
    // Shader ourShader("srcs/shaders/4.2.texture.vs", "srcs/shaders/4.2.texture.fs");
    Shader ourShader("srcs/shaders/5.1.transform.vs", "srcs/shaders/5.1.transform.fs");
    if (ourShader.error) {
        glfwTerminate();
        return EXIT_FAILURE;
    }    // Model *model = new Model();


    Model model;

    // load and create textures
    // -------------------------
    Texture texture1("resources/textures/container.jpg");
    Texture texture2("resources/textures/awesomeface.png", true);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    glUniform1i(glGetUniformLocation(ourShader.ID, "texture1"), 0);
    // or set it via the texture class
    ourShader.setInt("texture2", 1);

    // bind textures on corresponding texture units
    texture1.bind(0);
    texture2.bind(1);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(win))
    {
        // input
        // -----
        processInput(win);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // render container
        glBindVertexArray(model.VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    // Window destructor will destroy the GLFW window and terminate
    return EXIT_SUCCESS;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) // Wireframe mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if(glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) // Fill mode
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    static float offsetX = 0.0f;
    static float offsetY = 0.0f;
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        offsetX += 0.01f;
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        offsetX -= 0.01f;
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        offsetY += 0.01f;
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        offsetY -= 0.01f;
    // set the uniform
    int shaderProgram;
    glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProgram);
    int offsetLocation = glGetUniformLocation(shaderProgram, "uOffset");
    glUniform2f(offsetLocation, offsetX, offsetY);
    
    // create transformations
    glm::mat4 transform = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    transform = glm::translate(transform, glm::vec3(offsetX, offsetY, 0.0f));
    transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));

    // get matrix's uniform location and set matrix
    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));


    static float texMixValue = 0.2f;
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        texMixValue += 0.005f;
        if (texMixValue >= 1.0f)
            texMixValue = 1.0f;
    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        texMixValue -= 0.005f;
        if (texMixValue <= 0.0f)
            texMixValue = 0.0f;
    }
    // set the uniform texMixValue
    // glGetIntegerv(GL_CURRENT_PROGRAM, &shaderProgram);
    int texMixLocation = glGetUniformLocation(shaderProgram, "texMixValue");
    glUniform1f(texMixLocation, texMixValue);
    
    float timeValue = glfwGetTime();
    float colorMixValue = (sin(timeValue) / 2.0f) + 0.5f;
    int colorMixLocation = glGetUniformLocation(shaderProgram, "colorMixValue");
    glUniform1f(colorMixLocation, colorMixValue);
    // activate/deactivate texture with transition to color
    // if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
    // {

    // }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height);
} 