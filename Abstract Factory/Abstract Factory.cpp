#include <iostream>
#include <memory>


class Button {
public:
    virtual void render() const = 0;
    virtual ~Button() = default;
};


class Checkbox {
public:
    virtual void render() const = 0;
    virtual ~Checkbox() = default;
};


class WindowsButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Windows Button" << std::endl;
    }
};


class WindowsCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Rendering Windows Checkbox" << std::endl;
    }
};


class MacOSButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering macOS Button" << std::endl;
    }
};


class MacOSCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Rendering macOS Checkbox" << std::endl;
    }
};


class GUIFactory {
public:
    virtual std::shared_ptr<Button> createButton() const = 0;
    virtual std::shared_ptr<Checkbox> createCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};


class WindowsFactory : public GUIFactory {
public:
    std::shared_ptr<Button> createButton() const override {
        return std::make_shared<WindowsButton>();
    }

    std::shared_ptr<Checkbox> createCheckbox() const override {
        return std::make_shared<WindowsCheckbox>();
    }
};


class MacOSFactory : public GUIFactory {
public:
    std::shared_ptr<Button> createButton() const override {
        return std::make_shared<MacOSButton>();
    }

    std::shared_ptr<Checkbox> createCheckbox() const override {
        return std::make_shared<MacOSCheckbox>();
    }
};

int main() {
    std::shared_ptr<GUIFactory> factory;
    std::string osType = "MacOS";

    if (osType == "Windows") {
        factory = std::make_shared<WindowsFactory>();
    }
    else if (osType == "MacOS") {
        factory = std::make_shared<MacOSFactory>();
    }

    if (factory) {
        auto button = factory->createButton();
        auto checkbox = factory->createCheckbox();
        button->render();
        checkbox->render();
    }
    else {
        std::cout << "Unknown OS type!" << std::endl;
    }

    return 0;
}
